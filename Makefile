###############################
# Makefile for NDO
#
# Last Modified: 09-06-2009
###############################


# Source code directories
SRC_BASE=./src
SRC_INCLUDE=./include
SRC_CONFIG=./config

prefix=/usr/local/nagios
exec_prefix=${prefix}
LOGDIR=${prefix}/var
CFGDIR=${prefix}/etc
BINDIR=${exec_prefix}/bin
LIBEXECDIR=${exec_prefix}/libexec
INSTALL=/usr/bin/install -c
INSTALL_OPTS=-o nagios -g nagios
INIT_DIR=/etc/init.d
INIT_OPTS=-o root -g root

all:
	cd $(SRC_BASE) && $(MAKE)

ctags:
	ctags -R

install:
	cd $(SRC_BASE) && $(MAKE) $@
	@echo ""
	@echo "Main NDOUtils components installed"
	@echo ""

install-config:
	$(INSTALL) -m 775 $(INSTALL_OPTS) -d $(DESTDIR)$(CFGDIR)
	$(INSTALL) -b -m 664 $(INSTALL_OPTS) config/ndo2db.cfg-sample $(DESTDIR)$(CFGDIR)
	$(INSTALL) -b -m 664 $(INSTALL_OPTS) config/ndomod.cfg-sample $(DESTDIR)$(CFGDIR)
	@echo ""
	@echo "*** Config files installed ***"
	@echo ""
	@echo "Remember, these are *SAMPLE* config files.  You'll need to rename"
	@echo "the files in order to use them."
	@echo "Please read the documentation to know what they are doing."
	@echo ""

install-init: 
	$(INSTALL) -m 755 $(INIT_OPTS) -d $(DESTDIR)$(INIT_DIR)
	$(INSTALL) -m 755 $(INIT_OPTS) daemon-init $(DESTDIR)$(INIT_DIR)/ndo2db

fullinstall: install install-init install-config

clean:
	cd $(SRC_BASE) && $(MAKE) $@
	rm -f core
	rm -f *~ */*~ include/nagios-*/*~

distclean: clean
	cd $(SRC_BASE) && $(MAKE) $@
	cd docs/docbook/en-en/ && $(MAKE) $@
	rm -f config.log config.status config.cache 
	rm -f $(SRC_INCLUDE)/dh.h $(SRC_INCLUDE)/config.h
	rm -f $(SRC_CONFIG)/ndo2db.cfg-sample $(SRC_CONFIG)/ndomod.cfg-sample $(SRC_CONFIG)/nagios.cfg $(SRC_CONFIG)/misccommands.cfg
	rm -f Makefile
	rm -f subst daemon-init
	rm -f tags

devclean: distclean

