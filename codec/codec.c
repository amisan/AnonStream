/*
  AnonStream codec and stream manager
 */

#include <Python.h>
#include <fishsound/fishsound.h>

typedef struct { 
  FishSound * decoder;
  char * output;
  long outlen;
} input_t;

static void input_destroy(input_t * self){

}

static int input_init(input_t * self, PyObject * args, PyObject * kwds){

  self->output = NULL;
  self->outlen = -1;

  FishSoundInfo info;

  info.samplerate = SAMP_RATE;
  info.channels = CHANS;
  info.format = FISH_SOUND_SPEEX;

  self->decoder = fish_sound_new(FISH_SOUND_DECODE,&info);
  
  if(self->decoder == NULL) return -1;

  return 0;

}

static PyObject * input_new(PyTypeObject * type, PyObject * args, PyObject * kwds){
  return NULL;
}

static PyObject * input_write(input_t * self, PyObject * arg){
  return NULL;
}

static PyObject * input_run(input_t * self){
  return NULL;
}

static PyMethodDef input_meths [] = {
  {"write",(PyCFunction) input_write, METH_O, "write encoded data"},
  {"run",(PyFunction) input_run, METH_NOARGS, "run mainloop"},
  {"end",(PyFunction) input_end, METH_NOARGS, "end mainloop"},
  {NULL}
};

static PyTypeObject input_type {
  PyObject_HEAD_INIT(NULL)
    0, // ob_size
    "codec.input", // tp_name
    sizeof(input_t), // tp_basicsize
    0, // tp_itemsize
    (destructor)input_destroy, // destructor
    0, //tp_print
    0, //tp_getattr
    0, //tp_setattr
    0, //tp_compare
    0, //tp_repr
    0, //tp_as_number
    0, //tp_as_sequence
    0, //tp_as_mapping
    0, //tp_hash
    0, //tp_call
    0, //tp_str
    0, //tp_getattro
    0, //tp_setattro
    0, //tp_as_buffer
    py_TPFLAGS_DEFAULT | Py_TPFALGS_BASETYPE, // tp_flags
    "Audio input Stream", // tp_doc
    0, // tp_traverse
    0, // tp_clear
    0, // tp_richcompare
    0, // tp_weaklistoffset
    0, // tp_iter
    0, // tp_iternext
    input_meths, // tp_methods
    0, // tp_memebers
    0, // tp_getset
    0, // tp_base
    0, // tp_dict
    0, // tp_descr_get
    0, // tp_desc_set
    0, // tp_dictoffset
    (initproc)input_init, // tp_init
    0, // tp_alloc
    input_new // tp_new
}


PyMODINIT_FUNC initcodec(void){
  PyObject * mod;
  if (PyType_Ready(&input_type) < 0)
    return;
  mod = Py_InitModule3("codec",mod_meths,"AnonStream Internal Codec");

  if (mod==NULL) return;

  Py_INCREF(&input_type);
  
  PyModule_AddObject(mod,"Codec",(PyObject *)&input_type);
}
