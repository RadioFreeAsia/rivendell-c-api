HTML_DOCBOOK_STYLESHEETS=/usr/share/sgml/docbook/xsl-ns-stylesheets/xhtml/docbook.xsl
MAN_DOCBOOK_STYLESHEETS=/usr/share/sgml/docbook/xsl-ns-stylesheets/manpages/docbook.xsl
PDF_DOCBOOK_STYLSHEET=/usr/share/sgml/docbook/xsl-ns-stylesheets/fo/docbook.xsl

%.pdf:  %.xml
	xsltproc $(PDF_DOCBOOK_STYLSHEET) $< | fop - -pdf $@

pdf:	addcart.pdf\
        addcut.pdf\
        audioinfo.pdf\
        audiostore.pdf\
        deleteaudio.pdf\
        copyaudio.pdf\
        removecart.pdf\
        removecut.pdf\
        editcart.pdf\
        editcut.pdf\
        export.pdf\
        exportpeaks.pdf\
        import.pdf\
        listcart.pdf\
        listcarts.pdf\
        listcut.pdf\
        listcuts.pdf\
        listgroup.pdf\
        listgroups.pdf\
        listlog.pdf\
        listlogs.pdf\
        listservices.pdf\
        trimaudio.pdf\
        assignschedcode.pdf\
        unassignschedcode.pdf\
        listcartschedcodes.pdf\
        listschedcodes.pdf\
        clibsummary.pdf

%.html:	%.xml
	xsltproc -o	$@	$(HTML_DOCBOOK_STYLESHEETS)	$<

html:	addcart.html\
	addcut.html\
        audioinfo.html\
        audiostore.html\
	deleteaudio.html\
	copyaudio.html\
	removecart.html\
	removecut.html\
	editcart.html\
	editcut.html\
	export.html\
	exportpeaks.html\
	import.html\
        listcart.html\
        listcarts.html\
        listcut.html\
        listcuts.html\
        listgroup.html\
        listgroups.html\
        listlog.html\
        listlogs.html\
        listservices.html\
	trimaudio.html\
	assignschedcode.html\
	unassignschedcode.html\
	listcartschedcodes.html\
	listschedcodes.html\
	clibsummary.html


%.7:	%.xml
	xsltproc -o	$@	$(MAN_DOCBOOK_STYLESHEETS)	$<

7:	audiostore.7\
	addcart.7\
	addcut.7\
	audioinfo.7\
	deleteaudio.7\
	copyaudio.7\
	removecart.7\
	removecut.7\
	editcart.7\
	editcut.7\
	export.7\
	exportpeaks.7\
	import.7\
        listcart.7\
        listcarts.7\
        listcut.7\
        listcuts.7\
        listgroup.7\
        listgroups.7\
        listlogs.7\
        listservices.7\
        listlog.7\
	trimaudio.7\
	assignschedcode.7\
	unassignschedcode.7\
	listcartschedcodes.7\
	listschedcodes.7

