import os, socket
from bottle import route, request, static_file, run

#localIP = socket.gethostbyname(socket.gethostname())
localIP = '140.138.178.116'

@route('/')
def root():
    return static_file('test.html', root='.')
    
@route('/login', method='POST')
def do_login():
    
    account = request.params.get('account')
    password = request.params.get('password')
    print account
    if account in ('admin','upfly','ivy','kuo','dale','sam','tim','huang','hao') and password == '70808' :
        print "login ok"
        return '1'
    return '0'


@route('/upload', method='POST')
def do_upload():
    global globvarName
    global save_imgpath
    save_path = 'UserData_upload/'
    save_imgpath = save_path
    if not os.path.exists(save_path):
        os.makedirs(save_path)
    upload = request.files.get('Accelerometer')
    template = request.params.get('TemplateIndex')
    exe_str = 'SignalAnalysis.exe "'+save_path+str(upload.filename)+"\" "+template
    ##exe_str = '"C:\Users\\70808\Documents\Visual Studio 2013\Projects\SignalAnalysis\SignalAnalysis\SignalAnalysis.exe" '+str(upload.filename)+" "+template
    ##exe_str = '"C:\Users\70808\Desktop\SignalAnalysis\SignalAnalysis.exe" '+str(upload.filename)+" "+template
    ##exe_str ='''D:\SignalAnalysis.exe '''+'RecordByadminAt16_36_57.csv'+ ' '+ template
    print exe_str
    name, ext = os.path.splitext(upload.filename)
    
    globvarName = name
    if ext not in ('.csv'):
        return "File extension not allowed."
    
    ##save_path = "C:\Users\\70808\Documents\Visual Studio 2013\Projects\SignalAnalysis\SignalAnalysis"

    file_path = "{path}/{file}".format(path=save_path, file=upload.filename)
    upload.save(file_path)
    result = os.system(exe_str)
    print result 
    return str(result)
    #return "File successfully saved to '{0}'.".format(save_path)

    
@route('/image', method='GET')
def do_returnImage():
    ##img_file = "{filename}.{type}".format(filename=globvarName, type="png")
    print globvarName
    return static_file(save_imgpath+globvarName + '.png', root='.')


if __name__ == '__main__':
    run(host=localIP, port=8080)
