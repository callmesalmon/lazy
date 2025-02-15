all: install

SRCDIR  = .
LIBDIR  = /usr/include
LIB     = lazy.h
INSTALL = cp

install:
	@$(INSTALL)          \
		$(SRCDIR)/$(LIB) \
		$(LIBDIR)/$(LIB)
