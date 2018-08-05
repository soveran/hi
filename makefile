PREFIX?=/usr/local
MANPREFIX?=${PREFIX}/share/man
STRIP?=strip

default: hi

hi: hi.c
	$(CC) -Wall -Os -o hi hi.c

clean:
	@echo cleaning
	@rm -f hi

install: hi
	@echo stripping executable
	@${STRIP} hi
	@echo installing executable to ${PREFIX}/bin
	@mkdir -p ${PREFIX}/bin
	@cp -f hi ${PREFIX}/bin/hi
	@chmod 755 ${PREFIX}/bin/hi

	@echo installing manual pages to ${MANPREFIX}/man1
	@mkdir -p ${MANPREFIX}/man1
	@cp -f hi.1 ${MANPREFIX}/man1/hi.1
	@chmod 644 ${MANPREFIX}/man1/hi.1

uninstall:
	@echo removing executable from ${PREFIX}/bin
	@rm ${PREFIX}/bin/hi
	@echo removing manual pages from ${MANPREFIX}/man1
	@rm ${MANPREFIX}/man1/hi.1

test:
	@sh test/tests.sh

.PHONY: clean install uninstall test
