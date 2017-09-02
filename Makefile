.PHONY: clean All

All:
	@echo "----------Building project:[ rehabilitation - Debug ]----------"
	@"$(MAKE)" -f  "rehabilitation.mk"
clean:
	@echo "----------Cleaning project:[ rehabilitation - Debug ]----------"
	@"$(MAKE)" -f  "rehabilitation.mk" clean
