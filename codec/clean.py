#!/usr/bin/python
import util as cons
import os
def rm(name):
	if os.path.exists(name):
		cons.prnt('Removing %s ...'%name)
		os.remove(name)
try:
	rm('codec.o')
	rm('codec.so')
except Exception as e:
	cons.err(e)
