all: install

PWD     = .
INC     = /usr/include
LIB     = lazy.h
INSTALL = cp

install:
	@echo "Beginning installation..."
	@$(INSTALL)       \
		$(PWD)/$(LIB) \
		$(INC)/$(LIB)
	@echo "Installation done!"
