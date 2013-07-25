###############################
# Makefile for NDO
#
# Last Modified: 09-13-2009
###############################


prefix=/usr/local/nagios
exec_prefix=${prefix}
LOGDIR=${prefix}/var
CFGDIR=${prefix}/etc
BINDIR=${exec_prefix}/bin
LIBEXECDIR=${exec_prefix}/libexec
DATAROOTDIR=${prefix}/share
INSTALL=/usr/bin/install -c
INSTALL_OPTS=-o nagios -g nagios


all:
	@echo ""
	@echo "Please type what you want, possible targets:"
	@echo "make en-html"
	@echo "make en-html-singe"
	@echo "make en-pdf"
	@echo ""

en-html:
	xsltproc --xinclude ../xsl/html-chunked.xsl NDOUtils.xml
	

en-html-single:
	xsltproc --output ../../html/en-en/NDOUtils-single.html --xinclude ../xsl/html-single.xsl NDOUtils.xml

en-pdf:
	xsltproc --xinclude -o ../NDOUtils.fo ../xsl/fo.xsl ./NDOUtils.xml 
	fop ../NDOUtils.fo ../../NDOUtils-en.pdf
	rm -f ../NDOUtils.fo

distclean:
	rm -f Makefile
