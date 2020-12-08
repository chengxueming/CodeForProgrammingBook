libdir = /tmp
shared_objects = ./compress.lo
LIBTOOL = libtool
SHARED_LIBADD = -lz

compress.lo: compress.c
	$(LIBTOOL) --mode=compile gcc -c compress.c

libcompress.la: $(shared_objects)
	$(LIBTOOL) --mode=link gcc -o $@ -export-dynamic -avoid-version -prefer-pic -module -rpath $(libdir) $(shared_objects) $(SHARED_LIBADD)

$(libdir)/libcompress.la: libcompress.la
	$(LIBTOOL) --mode=install install -c libcompress.la $(libdir)

main.lo: main.c
	$(LIBTOOL) --mode=compile gcc -c main.c

# libtool --mode=link gcc -o main main.lo /tmp/libcompress.la
main: main.lo $(libdir)/libcompress.la
	$(LIBTOOL) --mode=link gcc -o $@ main.lo $(libdir)/libcompress.la

clean:
	rm -f /tmp/libcompress.*
	rm -r -f *.o *.lo *.la main .libs