all: tests

tests:
	make -f MakefileGtests all

exe:
	make -f MakefileApp all

clean:
	make -f MakefileGtests clean
	make -f MakefileApp clean

#find -type f -iname "*~" -exec rm {} \;