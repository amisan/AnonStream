// codec.h

/*
  AnonStream codec and stream manager
 */

// as you can see this is not even close to being done yet :|

#include <Python.h>
#include <fishsound/fishsound.h>

#define CHANS 1
#define SAMP_RATE 22050
#define INP_FORMAT FISH_SOUND_SPEEX
#define OUT_FORMAT FISH_SOUND_VORBIS

typedef struct { 
  FishSound * decoder;
  char * output;
  long outlen;
} input_t;

struct input_ll {
  struct input_ll * next;
  input_t * input;
};

typedef struct input_ll input_ll_t;

typedef struct{
  FishSound * encoder;
  input_ll_t * input_list;
  unsigned int input_len;
  unsigned int input_max;
} codec_t;

static void input_destroy(input_t * self);

static int input_init(input_t * self, PyObject * args, PyObject * kwds);

static PyObject * input_new(PyTypeObject * type, PyObject * args, PyObject * kwds);

static PyObject * input_write(input_t * self, PyObject * arg);

static PyObject * input_run(input_t * self);

static void codec_destroy(codec_t * self);

static int codec_init(codec_t * self, PyObject * args, PyObject * kwds);

static PyObject * codec_new(PyTypeObject * type, PyObject * args, PyObject * kwds);

int codec_encoded_callback(FishSound * encoder, unsigned char  * buff, 
			   long bytes,void * codec);




