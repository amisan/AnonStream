#!/usr/bin/python
import util as cons
try:
	import distutils.ccompiler
	cc = distutils.ccompiler.new_compiler()
	cons.prnt('Compile...')
	cc.compile(['codec.c'],include_dirs=['/usr/include/python3.1'],
		extra_preargs=['-fPIC','-Wall','-shared','-Wstrict-prototypes']
		)
	cons.prnt('Link...')
	cc.link(' ',['codec.o'],'codec.so',
		libraries=['vorbis','speex']
		)
	cons.prnt('Okay')
except Exception as e:
	cons.err('Compile Error: %s' %e)
