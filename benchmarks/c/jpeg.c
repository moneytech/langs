/*
  M to C  Whole Program Translator
  Input:  jpeg.m plus imported modules
  Output: \bench\c\jpeg.c (this file, or renamed from that)
          File represents entire program
  Target: C 64-bit
  OS:     Windows

  Modules:
  Module 1: jpeg.m
  Module 2: <Built-in: mlib.m>
  Module 3: <Built-in: msysnewc.m>
  Module 4: <Built-in: clibnewc.m>
  Module 5: <Built-in: oswindows.m>

*********** Start of C Code **********/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

#pragma pack(1)

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef unsigned char byte;

typedef void* var;

#ifndef CALLBACK
#define CALLBACK
#endif

#if (UINTPTR_MAX<0xFFFFFFFFFFFFFFFF)
	#error "Need 64-bit target. Try -m64"
#endif

/* Forward Struct Declarations */
struct mlib_strbuffer;
struct msysnewc_procinforec;
struct msysnewc_fmtrec;
struct oswindows_rsystemtime;
struct oswindows_input_record;
struct oswindows_rspoint;
struct oswindows_rsrect;
struct oswindows_rpoint;
struct oswindows_rconsole;
struct oswindows_rstartupinfo;
struct oswindows_rprocess_information;
struct oswindows_rwndclassex;
struct oswindows_rmsg;
struct jpeg_stream;
struct jpeg_huffnode;
struct jpeg_jpeginforec;

/* Struct Definitions */
struct mlib_strbuffer {
    byte *  strptr;
    i32 length;
    i32 allocated;
};

struct msysnewc_procinforec {
    u16 fnindex;
    byte rettype;
    byte nparams;
    byte paramlist[12];
};

struct msysnewc_fmtrec {
    byte minwidth;
    i8 precision;
    byte base;
    byte quotechar;
    byte padchar;
    byte realfmt;
    byte plus;
    byte sepchar;
    byte lettercase;
    byte justify;
    byte suffix;
    byte usigned;
    byte charmode;
    byte heapmode;
    byte param;
    byte spare;
};

struct oswindows_rsystemtime {
    u16 year;
    u16 month;
    u16 dayofweek;
    u16 day;
    u16 hour;
    u16 minute;
    u16 second;
    u16 milliseconds;
};

struct oswindows_input_record {
    u16 eventtype;
    u16 padding;
    u32 keydown;
    u16 repeatcount;
    u16 virtualkeycode;
    u16 virtualscancode;
    union {
        u16 unicodechar;
        byte asciichar;
    };
    u32 controlkeystate;
};

struct oswindows_rspoint {
    i16 x;
    i16 y;
};

struct oswindows_rsrect {
    i16 leftx;
    i16 top;
    i16 rightx;
    i16 bottom;
};

struct oswindows_rpoint {
    i32 x;
    i32 y;
};

struct oswindows_rconsole {
    struct oswindows_rspoint size;
    struct oswindows_rspoint pos;
    u16 attributes;
    struct oswindows_rsrect window;
    struct oswindows_rspoint maxwindowsize;
};

struct oswindows_rstartupinfo {
    u32 size;
    u32 dummy1;
    byte *  reserved;
    byte *  desktop;
    byte *  title;
    u32 x;
    u32 y;
    u32 xsize;
    u32 ysize;
    u32 xcountchars;
    u32 ycountchars;
    u32 fillattribute;
    u32 flags;
    u16 showwindow;
    u16 reserved2;
    u32 dummy2;
    void *  reserved4;
    void *  stdinput;
    void *  stdoutput;
    void *  stderror;
};

struct oswindows_rprocess_information {
    void *  process;
    void *  thread;
    u32 processid;
    u32 threadid;
};

struct oswindows_rwndclassex {
    u32 size;
    u32 style;
    void (*wndproc)(void);
    i32 clsextra;
    i32 wndextra;
    void *  instance;
    void *  icon;
    void *  cursor;
    void *  background;
    byte *  menuname;
    byte *  classname;
    void *  iconsm;
};

struct oswindows_rmsg {
    void *  hwnd;
    u32 message;
    u32 dummy1;
    u64 wparam;
    u64 lparam;
    u32 time;
    u32 dummy2;
    struct oswindows_rpoint pt;
};

struct jpeg_stream {
    byte *  ptr;
    byte *  ptrend;
    byte *  ptrstart;
    byte *  data;
    i64 currbyte;
    i64 currbit;
};

struct jpeg_huffnode {
    struct jpeg_huffnode* child0;
    struct jpeg_huffnode* child1;
    i64 symbol;
    i64 suppbits;
};

struct jpeg_jpeginforec {
    i64 width;
    i64 height;
    i64 ncomponents;
    i64 framebytes;
    i64 qtable[4][64];
    i64 comptype[4];
    i64 vsample[4];
    i64 hsample[4];
    i64 usedc[4];
    i64 useac[4];
    i64 useq[4];
    struct jpeg_huffnode *  dctable[4];
    struct jpeg_huffnode *  actable[4];
    i64 dri;
};


/* PROCDECLS */
void start(void);
byte * jpeg_loadjpeg(byte * file,i64 * width,i64 * height);
i64 jpeg_dllmain(i64 hinst,i64 reason,i64 reserved);
void jpeg_freejpeg(byte * p);
static void jpeg_initdata(void);
static void jpeg_showtree(struct jpeg_huffnode * tree,i64 level);
static void jpeg_initbitstream(struct jpeg_stream * fs);
static i64 jpeg_nextbit(struct jpeg_stream * fs);
static i64 jpeg_nextdatabyte(struct jpeg_stream * fs);
static struct jpeg_stream * jpeg_getstream(byte * filename);
static i64 jpeg_nextbyte(struct jpeg_stream * fs);
static i64 jpeg_readword(struct jpeg_stream * fs);
static void jpeg_readapp(struct jpeg_stream * fs,i64 n);
static void jpeg_read_dht(struct jpeg_stream * fs);
static struct jpeg_huffnode * jpeg_buildhufftree(i64 (*codelength)[],i64 (*symbols)[]);
static void jpeg_buildtreerec(struct jpeg_huffnode (*nodes)[],byte (*(*code)[])[],i64 (*symbol)[],i64 n,i64 bitx,i64 level);
static byte * (*jpeg_buildcanonical(i64 (*codelengths)[]))[];
static byte * jpeg_tostrbin(i64 a,i64 length);
static void jpeg_read_dqt(struct jpeg_stream * fs);
static void jpeg_read_sof(struct jpeg_stream * fs);
static void jpeg_read_sos(struct jpeg_stream * fs);
static void jpeg_read_eoi(struct jpeg_stream * fs);
static void jpeg_readmarker(struct jpeg_stream * fs);
static byte * jpeg_loadjpegfile(byte * file);
static byte * jpeg_loadscan(struct jpeg_stream * fs);
static i64 jpeg_tree_getsymbol(struct jpeg_stream * fs,struct jpeg_huffnode * node);
static i64 jpeg_getsymbol(struct jpeg_stream * fs,i64 nbits);
static void jpeg_unzigzag(i64 (*block)[64]);
static void jpeg_idct8x8(i64 (*block)[]);
static void jpeg_fastidct8(i64 * a1,i64 * a2,i64 * a3,i64 * a4,i64 * a5,i64 * a6,i64 * a7,i64 * a8);
static void jpeg_getblock(struct jpeg_stream * fs,struct jpeg_huffnode * dctree,struct jpeg_huffnode * actree,i64 (*block)[]);
static void jpeg_readblock(struct jpeg_stream * fs,i64 (*block)[],struct jpeg_huffnode * dctable,struct jpeg_huffnode * actable,i64 (*qtable)[],i64 * dc);
static byte * jpeg_loadcolour(struct jpeg_stream * fs,i64 hoz,i64 vert);
static void jpeg_reconsblockcolour(i64 (*lum1)[],i64 (*lum2)[],i64 (*lum3)[],i64 (*lum4)[],i64 (*cr)[],i64 (*cb)[],byte * data,i64 x,i64 y,i64 hoz,i64 vert);
static void * jpeg_jalloc(i64 n);
static void * jpeg_jallocz(i64 n);
static void jpeg_abortjpeg(byte * mess);
void * mlib_pcm_alloc(i64 n);
void mlib_pcm_freestr(byte * s);
void mlib_pcm_free(void * p,i64 n);
void mlib_pcm_freeac(void * p,i64 alloc);
void mlib_pcm_copymem4(void * p,void * q,i64 n);
void mlib_pcm_clearmem(void * p,i64 n);
void mlib_pcm_init(void);
i64 mlib_pcm_getac(i64 size);
void * mlib_pcm_newblock(i64 itemsize);
i64 mlib_pcm_round(i64 n);
i64 mlib_pcm_array(i64 n);
void mlib_pcm_printfreelist(i64 size,u64 * p);
void mlib_pcm_diags(byte * caption);
void * mlib_pcm_allocz(i64 n);
byte * mlib_pcm_copyheapstring(byte * s);
byte * mlib_pcm_copyheapstringn(byte * s,i64 n);
byte * mlib_pcm_copyheapblock(byte * s,i64 length);
static void mlib_addtomemalloc(i32 * ptr,i64 size);
static void mlib_removefrommemalloc(i32 * ptr,i64 size);
void * mlib_allocmem(i64 n);
void * mlib_reallocmem(void * p,i64 n);
void mlib_abortprogram(byte * s);
i64 mlib_getfilesize(void * handlex);
void mlib_readrandom(void * handlex,byte * mem,i64 offset,i64 size);
i64 mlib_writerandom(void * handlex,byte * mem,i64 offset,i64 size);
i64 mlib_setfilepos(void * file,i64 offset);
i64 mlib_getfilepos(void * file);
byte * mlib_readfile(byte * filename);
i64 mlib_writefile(byte * filename,byte * data,i64 size);
i64 mlib_checkfile(byte * file);
void mlib_readlinen(void * handlex,byte * buffer,i64 size);
void mlib_iconvlcn(byte * s,i64 n);
void mlib_iconvucn(byte * s,i64 n);
void mlib_convlcstring(byte * s);
void mlib_convucstring(byte * s);
byte * mlib_changeext(byte * s,byte * newext);
byte * mlib_extractext(byte * s,i64 period);
byte * mlib_extractpath(byte * s);
byte * mlib_extractfile(byte * s);
byte * mlib_extractbasefile(byte * s);
byte * mlib_addext(byte * s,byte * newext);
void * mlib_alloctable(i64 n,i64 size);
void * mlib_zalloctable(i64 n,i64 size);
void mlib_checkfreelists(byte * s);
void * mlib_pcm_alloc32(void);
void mlib_pcm_free32(void * p);
void mlib_outbyte(void * f,i64 x);
void mlib_outword16(void * f,u64 x);
void mlib_outword(void * f,u64 x);
void mlib_outword64(void * f,u64 x);
i64 mlib_myeof(void * f);
void * mlib_pcm_smallallocz(i64 n);
void * mlib_pcm_smallalloc(i64 n);
void mlib_strbuffer_add(struct mlib_strbuffer * dest,byte * s,i64 n);
void mlib_gs_init(struct mlib_strbuffer * dest);
void mlib_gs_free(struct mlib_strbuffer * dest);
void mlib_gs_str(struct mlib_strbuffer * dest,byte * s);
void mlib_gs_char(struct mlib_strbuffer * dest,i64 c);
void mlib_gs_strn(struct mlib_strbuffer * dest,byte * s,i64 length);
void mlib_gs_strvar(struct mlib_strbuffer * dest,struct mlib_strbuffer * s);
void mlib_gs_strint(struct mlib_strbuffer * dest,i64 a);
void mlib_gs_strln(struct mlib_strbuffer * dest,byte * s);
void mlib_gs_strsp(struct mlib_strbuffer * dest,byte * s);
void mlib_gs_line(struct mlib_strbuffer * dest);
i64 mlib_gs_getcol(struct mlib_strbuffer * dest);
void mlib_gs_leftstr(struct mlib_strbuffer * dest,byte * s,i64 w,i64 padch);
void mlib_gs_leftint(struct mlib_strbuffer * dest,i64 a,i64 w,i64 padch);
void mlib_gs_padto(struct mlib_strbuffer * dest,i64 col,i64 ch);
void mlib_gs_println(struct mlib_strbuffer * dest,void * f);
i64 mlib_nextcmdparam(i64 * paramno,byte * * name,byte * * value,byte * defext);
static i64 mlib_readnextfileitem(byte * * fileptr,byte * * item);
void mlib_ipadstr(byte * s,i64 width,byte * padchar);
byte * mlib_padstr(byte * s,i64 width,byte * padchar);
byte * mlib_chr(i64 c);
i64 mlib_cmpstring(byte * s,byte * t);
i64 mlib_cmpstringn(byte * s,byte * t,i64 n);
i64 mlib_eqstring(byte * s,byte * t);
i64 mlib_cmpbytes(void * p,void * q,i64 n);
i64 mlib_eqbytes(void * p,void * q,i64 n);
void mlib_mseed(u64 a,u64 b);
u64 mlib_mrandom(void);
i64 mlib_mrandomp(void);
i64 mlib_mrandomint(i64 n);
i64 mlib_mrandomrange(i64 a,i64 b);
double mlib_mrandomreal(void);
double mlib_mrandomreal1(void);
byte * mlib_checkpackfile(void);
i64 msysnewc_m_getdotindex(u64 a,i64 i);
void msysnewc_m_setdotindex(u64 * a,i64 i,i64 x);
i64 msysnewc_m_getdotslice(u64 a,i64 i,i64 j);
void msysnewc_m_setdotslice(u64 * a,i64 i,i64 j,u64 x);
i64 msysnewc_m_get_nprocs(void);
i64 msysnewc_m_get_nexports(void);
void * msysnewc_m_get_procname(i64 n);
byte * msysnewc_m_get_procaddr(i64 n);
void * msysnewc_m_get_procexport(i64 n);
static void msysnewc_pushio(void);
void msysnewc_m_print_startfile(void * dev);
void msysnewc_m_print_startstr(byte * s);
void msysnewc_m_print_startptr(byte * * p);
void msysnewc_m_print_startcon(void);
void msysnewc_m_print_setfmt(byte * format);
void msysnewc_m_print_end(void);
void msysnewc_m_print_ptr(void * a,byte * fmtstyle);
void msysnewc_m_print_i64(i64 a,byte * fmtstyle);
void msysnewc_m_print_u64(u64 a,byte * fmtstyle);
void msysnewc_m_print_r64(double x,byte * fmtstyle);
void msysnewc_m_print_r32(float x,byte * fmtstyle);
void msysnewc_m_print_c8(i64 a,byte * fmtstyle);
void msysnewc_m_print_str(byte * s,byte * fmtstyle);
void msysnewc_m_print_newline(void);
void msysnewc_m_print_nogap(void);
void msysnewc_printstr(byte * s);
void msysnewc_printstr_n(byte * s,i64 n);
void msysnewc_printstrn_app(byte * s,i64 length,void * f);
static byte * msysnewc_makezstring(byte * s,i64 n,byte * local);
static void msysnewc_freezstring(byte * t,i64 n);
static void msysnewc_printchar(i64 ch);
void msysnewc_nextfmtchars(i64 lastx);
void msysnewc_strtofmt(byte * s,i64 slen,struct msysnewc_fmtrec * fmt);
static i64 msysnewc_domultichar(byte * p,i64 n,byte * dest,struct msysnewc_fmtrec * fmt);
static i64 msysnewc_expandstr(byte * s,byte * t,i64 n,struct msysnewc_fmtrec * fmt);
static u64 msysnewc_xdivrem(u64 a,u64 b,u64 * remainder);
static i64 msysnewc_u64tostr(u64 aa,byte * s,u64 base,i64 sep);
static i64 msysnewc_i64tostrfmt(i64 aa,byte * s,struct msysnewc_fmtrec * fmt);
static i64 msysnewc_u64tostrfmt(i64 aa,byte * s,struct msysnewc_fmtrec * fmt);
static i64 msysnewc_i64mintostr(byte * s,i64 base,i64 sep);
static i64 msysnewc_strtostrfmt(byte * s,byte * t,i64 n,struct msysnewc_fmtrec * fmt);
static void msysnewc_tostr_i64(i64 a,struct msysnewc_fmtrec * fmt);
static void msysnewc_tostr_u64(u64 a,struct msysnewc_fmtrec * fmt);
static void msysnewc_tostr_r64(double x,struct msysnewc_fmtrec * fmt);
static void msysnewc_tostr_str(byte * s,struct msysnewc_fmtrec * fmt);
static struct msysnewc_fmtrec * msysnewc_getfmt(byte * fmtstyle);
byte * msysnewc_strint(i64 a,byte * fmtstyle);
void msysnewc_getstrint(i64 a,byte * dest);
byte * msysnewc_strword(u64 a,byte * fmtstyle);
byte * msysnewc_strreal(double a,byte * fmtstyle);
static byte * msysnewc_getstr(byte * s,struct msysnewc_fmtrec * fmt);
static void msysnewc_initreadbuffer(void);
void msysnewc_m_read_conline(void);
void msysnewc_m_read_fileline(void * f);
void msysnewc_m_read_strline(byte * s);
static byte * msysnewc_readitem(i64 * itemlength);
i64 msysnewc_strtoint(byte * s,i64 length,i64 base);
i64 msysnewc_m_read_i64(i64 fmt);
double msysnewc_m_read_r64(i64 fmt);
void msysnewc_m_read_str(byte * dest,i64 destlen,i64 fmt);
void msysnewc_readstr(byte * dest,i64 fmt,i64 destlen);
void msysnewc_rereadln(void);
void msysnewc_reread(void);
i64 msysnewc_valint(byte * s,i64 fmt);
double msysnewc_valreal(byte * s);
static void msysnewc_iconvlcn(byte * s,i64 n);
static void msysnewc_iconvucn(byte * s,i64 n);
static void msysnewc_convlcstring(byte * s);
static void msysnewc_convucstring(byte * s);
i64 msysnewc_m_power_i64(i64 n,i64 a);
void msysnewc_m_intoverflow(void);
void msysnewc_m_dotindex(u64 i,u64 a);
void msysnewc_m_dotslice(u64 j,u64 i,u64 a);
void msysnewc_m_popdotindex(u64 i,u64 * p,u64 x);
void msysnewc_m_popdotslice(u64 j,u64 i,u64 * p,u64 x);
i64 msysnewc_m_imin(i64 a,i64 b);
i64 msysnewc_m_imax(i64 a,i64 b);
double msysnewc_m_sign(double x);
extern void * GetStdHandle(u32 _1);
extern u32 GetConsoleScreenBufferInfo(void * _1,void * _2);
extern u32 SetConsoleCtrlHandler(void (*_1)(void),u32 _2);
extern u32 SetConsoleMode(void * _1,u32 _2);
extern u32 CreateProcessA(byte * _1,byte * _2,void * _3,void * _4,u32 _5,u32 _6,void * _7,byte * _8,void * _9,void * _10);
extern u32 GetLastError(void);
extern u32 WaitForSingleObject(void * _1,u32 _2);
extern u32 GetExitCodeProcess(void * _1,void * _2);
extern u32 CloseHandle(void * _1);
extern u32 GetNumberOfConsoleInputEvents(void * _1,void * _2);
extern u32 FlushConsoleInputBuffer(void * _1);
extern void * LoadLibraryA(byte * _1);
extern void * GetProcAddress(void * _1,byte * _2);
extern void * LoadCursorA(void * _1,byte * _2);
extern u32 RegisterClassExA(void * _1);
extern u32 DefWindowProcA(void * _1,u32 _2,u64 _3,u64 _4);
extern u32 ReadConsoleInputA(void * _1,void * _2,u32 _3,void * _4);
extern void Sleep(u32 _1);
extern u32 GetModuleFileNameA(void * _1,byte * _2,u32 _3);
extern void ExitProcess(u32 _1);
extern void PostQuitMessage(i32 _1);
extern void MessageBoxA(i32 x,byte * message,byte * caption,i32 y);
extern u32 QueryPerformanceCounter(i64 * _1);
extern u32 QueryPerformanceFrequency(i64 * _1);
extern void * CreateFileA(byte * _1,u32 _2,u32 _3,void * _4,u32 _5,u32 _6,void * _7);
extern u32 GetFileTime(void * _1,void * _2,void * _3,void * _4);
extern void GetSystemTime(struct oswindows_rsystemtime * _1);
extern void GetLocalTime(struct oswindows_rsystemtime * _1);
extern u32 GetTickCount(void);
extern u32 PeekMessageA(void * _1,void * * _2,u32 _3,u32 _4,u32 _5);
void oswindows_os_init(void);
i64 oswindows_os_execwait(byte * cmdline,i64 newconsole,byte * workdir);
i64 oswindows_os_execcmd(byte * cmdline,i64 newconsole);
i64 oswindows_os_getch(void);
i64 oswindows_os_kbhit(void);
void oswindows_os_flushkeys(void);
void * oswindows_os_getconsolein(void);
void * oswindows_os_getconsoleout(void);
void * oswindows_os_proginstance(void);
u64 oswindows_os_getdllinst(byte * name);
void * oswindows_os_getdllprocaddr(i64 hinst,byte * name);
void oswindows_os_initwindows(void);
void oswindows_os_gxregisterclass(byte * classname);
i64 oswindows_mainwndproc(void * hwnd,u32 message,u64 wparam,u64 lparam);
static void oswindows_timerproc(void * hwnd,i64 msg,i64 id,i64 time);
void oswindows_os_setmesshandler(void * addr);
i64 oswindows_os_getchx(void);
byte * oswindows_os_getos(void);
i64 oswindows_os_gethostsize(void);
i64 oswindows_os_shellexec(byte * opc,byte * file);
void oswindows_os_sleep(i64 a);
void * oswindows_os_getstdin(void);
void * oswindows_os_getstdout(void);
byte * oswindows_os_gethostname(void);
byte * oswindows_os_getmpath(void);
void oswindows_os_exitprocess(i64 x);
i64 oswindows_os_clock(void);
i64 oswindows_os_getclockspersec(void);
i64 oswindows_os_iswindows(void);
i64 oswindows_os_filelastwritetime(byte * filename);
void oswindows_os_getsystime(struct oswindows_rsystemtime * tm);
void oswindows_os_messagebox(byte * s,byte * t);
i64 oswindows_os_hpcounter(void);
i64 oswindows_os_hpfrequency(void);
void oswindows_os_peek(void);

/* VARS */
static i64 jpeg_debug = (i64)0;
static struct jpeg_jpeginforec jpeg_hdr;
i64 mlib_mdebug;
u64 mlib_allocupper[301];
i64 mlib_alloccode;
i64 mlib_allocbytes;
i64 mlib_fdebug = (i64)0;
i64 mlib_rfsize;
static u64 mlib_maxmemory;
static i64 mlib_maxalloccode;
static byte mlib_pcm_setup = (u8)0u;
static i64 mlib_show = (i64)0;
i64 mlib_memtotal = (i64)0;
i64 mlib_smallmemtotal = (i64)0;
i64 mlib_smallmemobjs = (i64)0;
i64 mlib_maxmemtotal = (i64)0;
static i32 *  mlib_memalloctable[500001];
static i32 mlib_memallocsize[500001];
static byte *  mlib_pcheapstart;
static byte *  mlib_pcheapend;
static byte *  mlib_pcheapptr;
static byte mlib_sizeindextable[2049];
u64 *  mlib_freelist[9];
byte *  mlib_pmnames[6] = {(byte*)"pm_end",(byte*)"pm_option",(byte*)"pm_sourcefile",(byte*)"pm_libfile",(byte*)"pm_colon",(byte*)"pm_extra"};
static i64 mlib_seed[2] = {(i64)2993073034246558322,(i64)1617678968452121188};
static void *  msysnewc__fnaddresses[]= {
    &start,
    &jpeg_loadjpeg,
    &jpeg_dllmain,
    &jpeg_freejpeg,
    &jpeg_initdata,
    &jpeg_showtree,
    &jpeg_initbitstream,
    &jpeg_nextbit,
    &jpeg_nextdatabyte,
    &jpeg_getstream,
    &jpeg_nextbyte,
    &jpeg_readword,
    &jpeg_readapp,
    &jpeg_read_dht,
    &jpeg_buildhufftree,
    &jpeg_buildtreerec,
    &jpeg_buildcanonical,
    &jpeg_tostrbin,
    &jpeg_read_dqt,
    &jpeg_read_sof,
    &jpeg_read_sos,
    &jpeg_read_eoi,
    &jpeg_readmarker,
    &jpeg_loadjpegfile,
    &jpeg_loadscan,
    &jpeg_tree_getsymbol,
    &jpeg_getsymbol,
    &jpeg_unzigzag,
    &jpeg_idct8x8,
    &jpeg_fastidct8,
    &jpeg_getblock,
    &jpeg_readblock,
    &jpeg_loadcolour,
    &jpeg_reconsblockcolour,
    &jpeg_jalloc,
    &jpeg_jallocz,
    &jpeg_abortjpeg,
    &mlib_pcm_alloc,
    &mlib_pcm_freestr,
    &mlib_pcm_free,
    &mlib_pcm_freeac,
    &mlib_pcm_copymem4,
    &mlib_pcm_clearmem,
    &mlib_pcm_init,
    &mlib_pcm_getac,
    &mlib_pcm_newblock,
    &mlib_pcm_round,
    &mlib_pcm_array,
    &mlib_pcm_printfreelist,
    &mlib_pcm_diags,
    &mlib_pcm_allocz,
    &mlib_pcm_copyheapstring,
    &mlib_pcm_copyheapstringn,
    &mlib_pcm_copyheapblock,
    &mlib_addtomemalloc,
    &mlib_removefrommemalloc,
    &mlib_allocmem,
    &mlib_reallocmem,
    &mlib_abortprogram,
    &mlib_getfilesize,
    &mlib_readrandom,
    &mlib_writerandom,
    &mlib_setfilepos,
    &mlib_getfilepos,
    &mlib_readfile,
    &mlib_writefile,
    &mlib_checkfile,
    &mlib_readlinen,
    &mlib_iconvlcn,
    &mlib_iconvucn,
    &mlib_convlcstring,
    &mlib_convucstring,
    &mlib_changeext,
    &mlib_extractext,
    &mlib_extractpath,
    &mlib_extractfile,
    &mlib_extractbasefile,
    &mlib_addext,
    &mlib_alloctable,
    &mlib_zalloctable,
    &mlib_checkfreelists,
    &mlib_pcm_alloc32,
    &mlib_pcm_free32,
    &mlib_outbyte,
    &mlib_outword16,
    &mlib_outword,
    &mlib_outword64,
    &mlib_myeof,
    &mlib_pcm_smallallocz,
    &mlib_pcm_smallalloc,
    &mlib_strbuffer_add,
    &mlib_gs_init,
    &mlib_gs_free,
    &mlib_gs_str,
    &mlib_gs_char,
    &mlib_gs_strn,
    &mlib_gs_strvar,
    &mlib_gs_strint,
    &mlib_gs_strln,
    &mlib_gs_strsp,
    &mlib_gs_line,
    &mlib_gs_getcol,
    &mlib_gs_leftstr,
    &mlib_gs_leftint,
    &mlib_gs_padto,
    &mlib_gs_println,
    &mlib_nextcmdparam,
    &mlib_readnextfileitem,
    &mlib_ipadstr,
    &mlib_padstr,
    &mlib_chr,
    &mlib_cmpstring,
    &mlib_cmpstringn,
    &mlib_eqstring,
    &mlib_cmpbytes,
    &mlib_eqbytes,
    &mlib_mseed,
    &mlib_mrandom,
    &mlib_mrandomp,
    &mlib_mrandomint,
    &mlib_mrandomrange,
    &mlib_mrandomreal,
    &mlib_mrandomreal1,
    &mlib_checkpackfile,
    &msysnewc_m_getdotindex,
    &msysnewc_m_setdotindex,
    &msysnewc_m_getdotslice,
    &msysnewc_m_setdotslice,
    &msysnewc_m_get_nprocs,
    &msysnewc_m_get_nexports,
    &msysnewc_m_get_procname,
    &msysnewc_m_get_procaddr,
    &msysnewc_m_get_procexport,
    &msysnewc_pushio,
    &msysnewc_m_print_startfile,
    &msysnewc_m_print_startstr,
    &msysnewc_m_print_startptr,
    &msysnewc_m_print_startcon,
    &msysnewc_m_print_setfmt,
    &msysnewc_m_print_end,
    &msysnewc_m_print_ptr,
    &msysnewc_m_print_i64,
    &msysnewc_m_print_u64,
    &msysnewc_m_print_r64,
    &msysnewc_m_print_r32,
    &msysnewc_m_print_c8,
    &msysnewc_m_print_str,
    &msysnewc_m_print_newline,
    &msysnewc_m_print_nogap,
    &msysnewc_printstr,
    &msysnewc_printstr_n,
    &msysnewc_printstrn_app,
    &msysnewc_makezstring,
    &msysnewc_freezstring,
    &msysnewc_printchar,
    &msysnewc_nextfmtchars,
    &msysnewc_strtofmt,
    &msysnewc_domultichar,
    &msysnewc_expandstr,
    &msysnewc_xdivrem,
    &msysnewc_u64tostr,
    &msysnewc_i64tostrfmt,
    &msysnewc_u64tostrfmt,
    &msysnewc_i64mintostr,
    &msysnewc_strtostrfmt,
    &msysnewc_tostr_i64,
    &msysnewc_tostr_u64,
    &msysnewc_tostr_r64,
    &msysnewc_tostr_str,
    &msysnewc_getfmt,
    &msysnewc_strint,
    &msysnewc_getstrint,
    &msysnewc_strword,
    &msysnewc_strreal,
    &msysnewc_getstr,
    &msysnewc_initreadbuffer,
    &msysnewc_m_read_conline,
    &msysnewc_m_read_fileline,
    &msysnewc_m_read_strline,
    &msysnewc_readitem,
    &msysnewc_strtoint,
    &msysnewc_m_read_i64,
    &msysnewc_m_read_r64,
    &msysnewc_m_read_str,
    &msysnewc_readstr,
    &msysnewc_rereadln,
    &msysnewc_reread,
    &msysnewc_valint,
    &msysnewc_valreal,
    &msysnewc_iconvlcn,
    &msysnewc_iconvucn,
    &msysnewc_convlcstring,
    &msysnewc_convucstring,
    &msysnewc_m_power_i64,
    &msysnewc_m_intoverflow,
    &msysnewc_m_dotindex,
    &msysnewc_m_dotslice,
    &msysnewc_m_popdotindex,
    &msysnewc_m_popdotslice,
    &msysnewc_m_imin,
    &msysnewc_m_imax,
    &msysnewc_m_sign,
    &oswindows_os_init,
    &oswindows_os_execwait,
    &oswindows_os_execcmd,
    &oswindows_os_getch,
    &oswindows_os_kbhit,
    &oswindows_os_flushkeys,
    &oswindows_os_getconsolein,
    &oswindows_os_getconsoleout,
    &oswindows_os_proginstance,
    &oswindows_os_getdllinst,
    &oswindows_os_getdllprocaddr,
    &oswindows_os_initwindows,
    &oswindows_os_gxregisterclass,
    &oswindows_mainwndproc,
    &oswindows_timerproc,
    &oswindows_os_setmesshandler,
    &oswindows_os_getchx,
    &oswindows_os_getos,
    &oswindows_os_gethostsize,
    &oswindows_os_shellexec,
    &oswindows_os_sleep,
    &oswindows_os_getstdin,
    &oswindows_os_getstdout,
    &oswindows_os_gethostname,
    &oswindows_os_getmpath,
    &oswindows_os_exitprocess,
    &oswindows_os_clock,
    &oswindows_os_getclockspersec,
    &oswindows_os_iswindows,
    &oswindows_os_filelastwritetime,
    &oswindows_os_getsystime,
    &oswindows_os_messagebox,
    &oswindows_os_hpcounter,
    &oswindows_os_hpfrequency,
    &oswindows_os_peek,
0};
static byte *  msysnewc__fnnames[]= {
    (byte*)"start",
    (byte*)"loadjpeg",
    (byte*)"dllmain",
    (byte*)"freejpeg",
    (byte*)"initdata",
    (byte*)"showtree",
    (byte*)"initbitstream",
    (byte*)"nextbit",
    (byte*)"nextdatabyte",
    (byte*)"getstream",
    (byte*)"nextbyte",
    (byte*)"readword",
    (byte*)"readapp",
    (byte*)"read_dht",
    (byte*)"buildhufftree",
    (byte*)"buildtreerec",
    (byte*)"buildcanonical",
    (byte*)"tostrbin",
    (byte*)"read_dqt",
    (byte*)"read_sof",
    (byte*)"read_sos",
    (byte*)"read_eoi",
    (byte*)"readmarker",
    (byte*)"loadjpegfile",
    (byte*)"loadscan",
    (byte*)"tree_getsymbol",
    (byte*)"getsymbol",
    (byte*)"unzigzag",
    (byte*)"idct8x8",
    (byte*)"fastidct8",
    (byte*)"getblock",
    (byte*)"readblock",
    (byte*)"loadcolour",
    (byte*)"reconsblockcolour",
    (byte*)"jalloc",
    (byte*)"jallocz",
    (byte*)"abortjpeg",
    (byte*)"pcm_alloc",
    (byte*)"pcm_freestr",
    (byte*)"pcm_free",
    (byte*)"pcm_freeac",
    (byte*)"pcm_copymem4",
    (byte*)"pcm_clearmem",
    (byte*)"pcm_init",
    (byte*)"pcm_getac",
    (byte*)"pcm_newblock",
    (byte*)"pcm_round",
    (byte*)"pcm_array",
    (byte*)"pcm_printfreelist",
    (byte*)"pcm_diags",
    (byte*)"pcm_allocz",
    (byte*)"pcm_copyheapstring",
    (byte*)"pcm_copyheapstringn",
    (byte*)"pcm_copyheapblock",
    (byte*)"addtomemalloc",
    (byte*)"removefrommemalloc",
    (byte*)"allocmem",
    (byte*)"reallocmem",
    (byte*)"abortprogram",
    (byte*)"getfilesize",
    (byte*)"readrandom",
    (byte*)"writerandom",
    (byte*)"setfilepos",
    (byte*)"getfilepos",
    (byte*)"readfile",
    (byte*)"writefile",
    (byte*)"checkfile",
    (byte*)"readlinen",
    (byte*)"iconvlcn",
    (byte*)"iconvucn",
    (byte*)"convlcstring",
    (byte*)"convucstring",
    (byte*)"changeext",
    (byte*)"extractext",
    (byte*)"extractpath",
    (byte*)"extractfile",
    (byte*)"extractbasefile",
    (byte*)"addext",
    (byte*)"alloctable",
    (byte*)"zalloctable",
    (byte*)"checkfreelists",
    (byte*)"pcm_alloc32",
    (byte*)"pcm_free32",
    (byte*)"outbyte",
    (byte*)"outword16",
    (byte*)"outword",
    (byte*)"outword64",
    (byte*)"myeof",
    (byte*)"pcm_smallallocz",
    (byte*)"pcm_smallalloc",
    (byte*)"strbuffer_add",
    (byte*)"gs_init",
    (byte*)"gs_free",
    (byte*)"gs_str",
    (byte*)"gs_char",
    (byte*)"gs_strn",
    (byte*)"gs_strvar",
    (byte*)"gs_strint",
    (byte*)"gs_strln",
    (byte*)"gs_strsp",
    (byte*)"gs_line",
    (byte*)"gs_getcol",
    (byte*)"gs_leftstr",
    (byte*)"gs_leftint",
    (byte*)"gs_padto",
    (byte*)"gs_println",
    (byte*)"nextcmdparam",
    (byte*)"readnextfileitem",
    (byte*)"ipadstr",
    (byte*)"padstr",
    (byte*)"chr",
    (byte*)"cmpstring",
    (byte*)"cmpstringn",
    (byte*)"eqstring",
    (byte*)"cmpbytes",
    (byte*)"eqbytes",
    (byte*)"mseed",
    (byte*)"mrandom",
    (byte*)"mrandomp",
    (byte*)"mrandomint",
    (byte*)"mrandomrange",
    (byte*)"mrandomreal",
    (byte*)"mrandomreal1",
    (byte*)"checkpackfile",
    (byte*)"m_getdotindex",
    (byte*)"m_setdotindex",
    (byte*)"m_getdotslice",
    (byte*)"m_setdotslice",
    (byte*)"m_get_nprocs",
    (byte*)"m_get_nexports",
    (byte*)"m_get_procname",
    (byte*)"m_get_procaddr",
    (byte*)"m_get_procexport",
    (byte*)"pushio",
    (byte*)"m_print_startfile",
    (byte*)"m_print_startstr",
    (byte*)"m_print_startptr",
    (byte*)"m_print_startcon",
    (byte*)"m_print_setfmt",
    (byte*)"m_print_end",
    (byte*)"m_print_ptr",
    (byte*)"m_print_i64",
    (byte*)"m_print_u64",
    (byte*)"m_print_r64",
    (byte*)"m_print_r32",
    (byte*)"m_print_c8",
    (byte*)"m_print_str",
    (byte*)"m_print_newline",
    (byte*)"m_print_nogap",
    (byte*)"printstr",
    (byte*)"printstr_n",
    (byte*)"printstrn_app",
    (byte*)"makezstring",
    (byte*)"freezstring",
    (byte*)"printchar",
    (byte*)"nextfmtchars",
    (byte*)"strtofmt",
    (byte*)"domultichar",
    (byte*)"expandstr",
    (byte*)"xdivrem",
    (byte*)"u64tostr",
    (byte*)"i64tostrfmt",
    (byte*)"u64tostrfmt",
    (byte*)"i64mintostr",
    (byte*)"strtostrfmt",
    (byte*)"tostr_i64",
    (byte*)"tostr_u64",
    (byte*)"tostr_r64",
    (byte*)"tostr_str",
    (byte*)"getfmt",
    (byte*)"strint",
    (byte*)"getstrint",
    (byte*)"strword",
    (byte*)"strreal",
    (byte*)"getstr",
    (byte*)"initreadbuffer",
    (byte*)"m_read_conline",
    (byte*)"m_read_fileline",
    (byte*)"m_read_strline",
    (byte*)"readitem",
    (byte*)"strtoint",
    (byte*)"m_read_i64",
    (byte*)"m_read_r64",
    (byte*)"m_read_str",
    (byte*)"readstr",
    (byte*)"rereadln",
    (byte*)"reread",
    (byte*)"valint",
    (byte*)"valreal",
    (byte*)"iconvlcn",
    (byte*)"iconvucn",
    (byte*)"convlcstring",
    (byte*)"convucstring",
    (byte*)"m_power_i64",
    (byte*)"m_intoverflow",
    (byte*)"m_dotindex",
    (byte*)"m_dotslice",
    (byte*)"m_popdotindex",
    (byte*)"m_popdotslice",
    (byte*)"m_imin",
    (byte*)"m_imax",
    (byte*)"m_sign",
    (byte*)"os_init",
    (byte*)"os_execwait",
    (byte*)"os_execcmd",
    (byte*)"os_getch",
    (byte*)"os_kbhit",
    (byte*)"os_flushkeys",
    (byte*)"os_getconsolein",
    (byte*)"os_getconsoleout",
    (byte*)"os_proginstance",
    (byte*)"os_getdllinst",
    (byte*)"os_getdllprocaddr",
    (byte*)"os_initwindows",
    (byte*)"os_gxregisterclass",
    (byte*)"mainwndproc",
    (byte*)"timerproc",
    (byte*)"os_setmesshandler",
    (byte*)"os_getchx",
    (byte*)"os_getos",
    (byte*)"os_gethostsize",
    (byte*)"os_shellexec",
    (byte*)"os_sleep",
    (byte*)"os_getstdin",
    (byte*)"os_getstdout",
    (byte*)"os_gethostname",
    (byte*)"os_getmpath",
    (byte*)"os_exitprocess",
    (byte*)"os_clock",
    (byte*)"os_getclockspersec",
    (byte*)"os_iswindows",
    (byte*)"os_filelastwritetime",
    (byte*)"os_getsystime",
    (byte*)"os_messagebox",
    (byte*)"os_hpcounter",
    (byte*)"os_hpfrequency",
    (byte*)"os_peek",
(byte*)""};
static struct msysnewc_procinforec msysnewc__fnexports[]= {
	{0, 0,0, {0,0,0, 0,0,0, 0,0,0, 0,0,0}}}
;
static i64 msysnewc__fnnprocs=237;
static i64 msysnewc__fnnexports=0;
static i64 msysnewc_fmtparam;
i64 msysnewc_needgap = (i64)0;
static i64 msysnewc_outdev = (i64)1;
static void *  msysnewc_outchan = 0;
static byte *  msysnewc_fmtstr = 0;
static void *  msysnewc_outchan_stack[10];
static i64 msysnewc_outdev_stack[10];
static byte *  msysnewc_fmtstr_stack[10];
static byte msysnewc_needgap_stack[10];
static byte *  msysnewc_ptr_stack[10];
static i64 msysnewc_niostack = (i64)0;
static byte msysnewc_digits[16] = {
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    'A',
    'B',
    'C',
    'D',
    'E',
    'F'
};
static struct msysnewc_fmtrec msysnewc_defaultfmt = {
    (u8)0u,
    (i8)0,
    (u8)10u,
    (u64)0u,
    ' ',
    'f',
    (u64)0u,
    (u64)0u,
    (u64)0u,
    'R',
    (u64)0u,
    (u64)0u,
    (u64)0u,
    (u64)0u,
    (u64)0u,
    (u8)0u
};
static byte *  msysnewc_rd_buffer;
static i64 msysnewc_rd_length;
static byte *  msysnewc_rd_pos;
static byte *  msysnewc_rd_lastpos;
static i64 msysnewc_termchar;
static i64 msysnewc_itemerror;
i64 msysnewc_nsysparams;
byte *  msysnewc_sysparams[128];
static u64 msysnewc_callbackstack[9][8];
static i64 msysnewc_ncallbacks = (i64)0;
static u64 msysnewc_mask63 = (u64)9223372036854775807u;
static double msysnewc_offset64 = (double)9223372036854775800.;
static double msysnewc_offset32 = (double)9223372036854775800.;
static void *  oswindows_hconsole;
static void *  oswindows_hconsolein;
static struct oswindows_input_record oswindows_lastkey;
static struct oswindows_input_record oswindows_pendkey;
static i64 oswindows_keypending;
static i64 (*oswindows_wndproc_callbackfn)(void *) = 0;
static i64 oswindows_init_flag = (i64)0;

/* PROCDEFS */
// START
void start(void) {
    byte *  p;
    byte *  file;
    i64 width;
    i64 height;
    i64 av_1;
    file = (byte*)"\\jpeg\\wtc-photo.jpg";
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"FILE=",NULL);
    msysnewc_m_print_str(file,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"&HDR=",NULL);
    msysnewc_m_print_ptr(&jpeg_hdr,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"LOADING... 23456/CC",NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    p = jpeg_loadjpeg(file,&width,&height);
    if ((p == 0)) {
        msysnewc_m_print_startcon();
        msysnewc_m_print_str((byte*)"Couldn't load",NULL);
        msysnewc_m_print_str(file,NULL);
        msysnewc_m_print_newline();
        msysnewc_m_print_end();
        ;
        exit(0);
    };
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"REF VOID(P)=",NULL);
    msysnewc_m_print_ptr((void *)(p),NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"WIDTH=",NULL);
    msysnewc_m_print_i64(width,NULL);
    msysnewc_m_print_str((byte*)"HEIGHT=",NULL);
    msysnewc_m_print_i64(height,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    av_1 = (i64)100;
    while (av_1-- > 0) {
L1 :;
        msysnewc_m_print_startcon();
        msysnewc_m_print_u64((*p),NULL);
        msysnewc_m_print_nogap();
        msysnewc_m_print_str((byte*)" ",NULL);
        msysnewc_m_print_end();
        ;
        ++p;
L2 :;
    }L3 :;
    ;
    msysnewc_m_print_startcon();
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
}

int main(int nargs, char** args) {
int i;
	msysnewc_nsysparams=nargs;
	if (msysnewc_nsysparams>nargs) {puts("Too many params"); exit(1);}
	for (i=1; i<=nargs; ++i) msysnewc_sysparams[i-1]=(byte*)args[i-1];


	start();
	return 0;
}

byte * jpeg_loadjpeg(byte * file,i64 * width,i64 * height) {
    byte *  p;
    (*width) = ((*height) = (i64)-1);
    p = jpeg_loadjpegfile(file);
    (*width) = jpeg_hdr.width;
    (*height) = jpeg_hdr.height;
    return p;
}

CALLBACK i64 jpeg_dllmain(i64 hinst,i64 reason,i64 reserved) {
    return (i64)1;
}

void jpeg_freejpeg(byte * p) {
    free((void *)(p));
}

static void jpeg_initdata(void) {
    mlib_pcm_init();
    memset((void *)(&jpeg_hdr),(i64)0,(u64)((i64)2344));
}

static void jpeg_showtree(struct jpeg_huffnode * tree,i64 level) {
    static i64 seq = (i64)0;
    i64 av_1;
    if ((tree == 0)) {
        return;
    };
    msysnewc_m_print_startcon();
    msysnewc_m_print_i64(++seq,NULL);
    msysnewc_m_print_end();
    ;
    av_1 = level;
    while (av_1-- > 0) {
L4 :;
        msysnewc_m_print_startcon();
        msysnewc_m_print_str((byte*)"    ",NULL);
        msysnewc_m_print_end();
        ;
L5 :;
    }L6 :;
    ;
    msysnewc_m_print_startcon();
    msysnewc_m_print_i64((*tree).symbol,NULL);
    msysnewc_m_print_i64((*tree).suppbits,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    jpeg_showtree((*tree).child0,(level + (i64)1));
    jpeg_showtree((*tree).child1,(level + (i64)1));
}

static void jpeg_initbitstream(struct jpeg_stream * fs) {
    (*fs).currbyte = (i64)0;
    (*fs).currbit = (i64)1;
}

static i64 jpeg_nextbit(struct jpeg_stream * fs) {
    if (((*fs).currbit == (i64)1)) {
        (*fs).currbyte = jpeg_nextdatabyte(fs);
        (*fs).currbit = (i64)256;
    };
    (*fs).currbit >>= (i64)1;
    return (!!(((*fs).currbyte & (*fs).currbit))?(i64)1:(i64)0);
}

static i64 jpeg_nextdatabyte(struct jpeg_stream * fs) {
    i64 c;
    L7 :;
    while (1) {
        if (((c = jpeg_nextbyte(fs)) != (i64)255)) {
            return c;
        };
        L9 :;
        do {
            c = jpeg_nextbyte(fs);
L10 :;
        } while (!(c != (i64)255));L11 :;
        ;
        if ((c == (i64)0)) {
            return (i64)255;
        };
    }L8 :;
    ;
    return (i64)0;
}

static struct jpeg_stream * jpeg_getstream(byte * filename) {
    struct jpeg_stream *  fs;
    fs = (struct jpeg_stream *)(jpeg_jalloc((i64)48));
    (*fs).data = mlib_readfile(filename);
    if (((*fs).data == 0)) {
        msysnewc_m_print_startcon();
        msysnewc_m_print_str((byte*)"JPEGDLL:Can't open",NULL);
        msysnewc_m_print_str(filename,NULL);
        msysnewc_m_print_newline();
        msysnewc_m_print_end();
        ;
        return (struct jpeg_stream *)(0);
    };
    (*fs).ptr = (*fs).data;
    (*fs).ptrend = ((*fs).ptr + mlib_rfsize);
    (*fs).ptrstart = (*fs).ptr;
    return fs;
}

static i64 jpeg_nextbyte(struct jpeg_stream * fs) {
    i64 c;
    if (((*fs).ptr < (*fs).ptrend)) {
        c = (i64)((*(*fs).ptr));
        ++(*fs).ptr;
        return c;
    };
    jpeg_abortjpeg((byte*)"nextbyte");
    return (i64)-1;
}

static i64 jpeg_readword(struct jpeg_stream * fs) {
    i64 bb;
    bb = jpeg_nextbyte(fs);
    return ((bb << (i64)8) | jpeg_nextbyte(fs));
}

static void jpeg_readapp(struct jpeg_stream * fs,i64 n) {
    byte *  ptr;
    i64 length;
    length = (jpeg_readword(fs) - (i64)2);
    ptr = (*fs).ptr;
    (*fs).ptr = (ptr + length);
}

static void jpeg_read_dht(struct jpeg_stream * fs) {
    i64 length;
    i64 tot;
    i64 t;
    i64 tabno;
    i64 tabtype;
    i64 i;
    i64 codeswithlength[16];
    i64 symbol[256];
    struct jpeg_huffnode *  tree;
    length = (jpeg_readword(fs) - (i64)2);
    L12 :;
    while ((length > (i64)0)) {
        t = jpeg_nextbyte(fs);
        tabno = (t & (i64)15);
        tabtype = ((t >> (i64)4) & (i64)15);
        tot = (i64)0;
        L15 :;
        for (i=(i64)1;i<=(i64)16;i+=(i64)1) {
L16 :;
            codeswithlength[(i)-1] = jpeg_nextbyte(fs);
            tot += codeswithlength[(i)-1];
L17 :;
        }L18 :;
        ;
        L19 :;
        for (i=(i64)1;i<=tot;i+=(i64)1) {
L20 :;
            symbol[(i)-1] = jpeg_nextbyte(fs);
L21 :;
        }L22 :;
        ;
        tree = jpeg_buildhufftree(&codeswithlength,&symbol);
        if ((tabtype == (i64)0)) {
            jpeg_hdr.dctable[((tabno + (i64)1))-1] = tree;
        } else {
            jpeg_hdr.actable[((tabno + (i64)1))-1] = tree;
        };
        length -= ((tot + (i64)16) + (i64)1);
L13 :;
    }L14 :;
    ;
}

static struct jpeg_huffnode * jpeg_buildhufftree(i64 (*codelength)[],i64 (*symbols)[]) {
    struct jpeg_huffnode (*nodes)[];
    byte * (*codes)[];
    i64 tot;
    i64 i;
    tot = (i64)0;
    L23 :;
    for (i=(i64)1;i<=(i64)16;i+=(i64)1) {
L24 :;
        tot += (*codelength)[(i)-1];
L25 :;
    }L26 :;
    ;
    nodes = (struct jpeg_huffnode (*)[])(jpeg_jallocz(((i64)32 * ((tot * (i64)2) - (i64)1))));
    codes = jpeg_buildcanonical(codelength);
    jpeg_buildtreerec(nodes,(byte (*(*)[])[])(&(*codes)[((i64)1)-1]),(i64 (*)[])(&(*symbols)[((i64)1)-1]),tot,(i64)0,(i64)0);
    return (struct jpeg_huffnode *)(nodes);
}

static void jpeg_buildtreerec(struct jpeg_huffnode (*nodes)[],byte (*(*code)[])[],i64 (*symbol)[],i64 n,i64 bitx,i64 level) {
    struct jpeg_huffnode *  first;
    i64 i;
    i64 i2;
    i64 k;
    if ((n == (i64)0)) {
        return;
    };
    first = &(*nodes)[((i64)1)-1];
    if ((n == (i64)1)) {
        (*first).child0 = (struct jpeg_huffnode *)(0);
        (*first).child1 = (struct jpeg_huffnode *)(0);
        (*first).symbol = (*symbol)[((i64)1)-1];
        (*first).suppbits = (i64)0;
        k = ((i64)(strlen((i8 *)((*code)[((i64)1)-1]))) - bitx);
        if ((k > (i64)0)) {
            (*first).suppbits = k;
            bitx += k;
        };
        return;
    };
    L27 :;
    for (i2=(i64)1;i2<=n;i2+=(i64)1) {
L28 :;
        if (((u64)((*(*code)[(i2)-1])[((bitx + (i64)1))-1]) == '1')) {
            i = i2;
            goto L30 ;
        };
        i = i2;
L29 :;
    }L30 :;
    ;
    (*first).child0 = &(*nodes)[((i64)2)-1];
    (*first).child1 = &(*nodes)[((((i64)2 * i) - (i64)1))-1];
    (*first).symbol = (i64)-1;
    (*first).suppbits = (i64)0;
    jpeg_buildtreerec((struct jpeg_huffnode (*)[])(&(*nodes)[((i64)2)-1]),code,symbol,(i - (i64)1),(bitx + (i64)1),(level + (i64)1));
    jpeg_buildtreerec((struct jpeg_huffnode (*)[])(&(*nodes)[((((i64)2 * i) - (i64)1))-1]),(byte (*(*)[])[])(&(*code)[(i)-1]),(i64 (*)[])(&(*symbol)[(i)-1]),((n - i) + (i64)1),(bitx + (i64)1),(level + (i64)1));
}

static byte * (*jpeg_buildcanonical(i64 (*codelengths)[]))[] {
    i64 i;
    i64 j;
    i64 n;
    i64 code;
    i64 length;
    byte * (*a)[];
    i64 av_1;
    n = (i64)0;
    L31 :;
    for (i=(i64)1;i<=(i64)16;i+=(i64)1) {
L32 :;
        n += (*codelengths)[(i)-1];
L33 :;
    }L34 :;
    ;
    a = (byte * (*)[])(jpeg_jallocz((n * (i64)8)));
    j = (i64)1;
    code = (i64)0;
    length = (i64)1;
    L35 :;
    for (i=(i64)1;i<=(i64)16;i+=(i64)1) {
L36 :;
        av_1 = (*codelengths)[(i)-1];
        while (av_1-- > 0) {
L39 :;
            (*a)[(j)-1] = mlib_pcm_copyheapstring(jpeg_tostrbin(code,length));
            ++j;
            ++code;
L40 :;
        }L41 :;
        ;
        code <<= (i64)1;
        ++length;
L37 :;
    }L38 :;
    ;
    return a;
}

static byte * jpeg_tostrbin(i64 a,i64 length) {
    static byte result[65];
    i64 i;
    result[((length + (i64)1))-1] = (u64)0u;
    L42 :;
    for (i=length;i>=(i64)1;i-=(i64)1) {
L43 :;
        result[(i)-1] = (u64)(((i64)48 + (a & (i64)1)));
        a >>= (i64)1;
L44 :;
    }L45 :;
    ;
    return result;
}

static void jpeg_read_dqt(struct jpeg_stream * fs) {
    i64 lq;
    i64 i;
    i64 pq;
    i64 tq;
    lq = (jpeg_readword(fs) - (i64)2);
    L46 :;
    while ((lq > (i64)0)) {
        tq = jpeg_nextbyte(fs);
        pq = (tq >> (i64)4);
        tq &= (i64)15;
        ++tq;
        --lq;
        if ((pq == (i64)0)) {
            L49 :;
            for (i=(i64)1;i<=(i64)64;i+=(i64)1) {
L50 :;
                jpeg_hdr.qtable[(tq)-1][(i)-1] = jpeg_nextbyte(fs);
L51 :;
            }L52 :;
            ;
        } else {
            L53 :;
            for (i=(i64)1;i<=(i64)64;i+=(i64)1) {
L54 :;
                jpeg_hdr.qtable[(tq)-1][(i)-1] = jpeg_readword(fs);
L55 :;
            }L56 :;
            ;
        };
        lq -= (i64)64;
L47 :;
    }L48 :;
    ;
}

static void jpeg_read_sof(struct jpeg_stream * fs) {
    i64 precision;
    i64 i;
    i64 sampling;
    i64 av_1;
    jpeg_readword(fs);
    precision = jpeg_nextbyte(fs);
    if ((precision != (i64)8)) {
        jpeg_abortjpeg((byte*)"PRECISION");
    };
    jpeg_hdr.height = jpeg_readword(fs);
    jpeg_hdr.width = jpeg_readword(fs);
    jpeg_hdr.ncomponents = jpeg_nextbyte(fs);
    jpeg_hdr.framebytes = ((jpeg_hdr.width * jpeg_hdr.height) * jpeg_hdr.ncomponents);
    L57 :;
    for (i=(i64)1;i<=jpeg_hdr.ncomponents;i+=(i64)1) {
L58 :;
        jpeg_hdr.comptype[(i)-1] = jpeg_nextbyte(fs);
        sampling = jpeg_nextbyte(fs);
        jpeg_hdr.vsample[(i)-1] = (sampling & (i64)15);
        jpeg_hdr.hsample[(i)-1] = (sampling >> (i64)4);
        jpeg_hdr.useq[(i)-1] = (jpeg_nextbyte(fs) + (i64)1);
L59 :;
    }L60 :;
    ;
}

static void jpeg_read_sos(struct jpeg_stream * fs) {
    i64 length;
    i64 ns;
    i64 i;
    i64 t;
    length = (jpeg_readword(fs) - (i64)2);
    ns = jpeg_nextbyte(fs);
    if ((ns != jpeg_hdr.ncomponents)) {
        jpeg_abortjpeg((byte*)"NCOMPS<>NS");
    };
    L61 :;
    for (i=(i64)1;i<=ns;i+=(i64)1) {
L62 :;
        jpeg_hdr.comptype[(i)-1] = jpeg_nextbyte(fs);
        t = jpeg_nextbyte(fs);
        jpeg_hdr.usedc[(i)-1] = ((t >> (i64)4) + (i64)1);
        jpeg_hdr.useac[(i)-1] = ((t & (i64)15) + (i64)1);
L63 :;
    }L64 :;
    ;
    length -= ((ns * (i64)2) + (i64)1);
    L65 :;
    while (!!(length--)) {
        jpeg_nextbyte(fs);
L66 :;
    }L67 :;
    ;
}

static void jpeg_read_eoi(struct jpeg_stream * fs) {
    i64 c;
    if ((jpeg_nextbyte(fs) != (i64)255)) {
        jpeg_abortjpeg((byte*)"EOI FF");
    };
    L68 :;
    do {
        c = jpeg_nextbyte(fs);
L69 :;
    } while (!(c != (i64)255));L70 :;
    ;
    if ((c != (i64)217)) {
        jpeg_abortjpeg((byte*)"EOI D9");
    };
}

static void jpeg_readmarker(struct jpeg_stream * fs) {
    jpeg_nextbyte(fs);
    jpeg_nextbyte(fs);
    jpeg_initbitstream(fs);
}

static byte * jpeg_loadjpegfile(byte * file) {
    struct jpeg_stream *  fs;
    byte *  pimage;
    i64 c;
    jpeg_initdata();
    pimage = (byte *)(0);
    fs = jpeg_getstream(file);
    if (!(!!(fs))) {
        return (byte *)(0);
    };
    L71 :;
    while (1) {
        c = jpeg_nextbyte(fs);
        if ((c == (i64)255)) {
            c = jpeg_nextbyte(fs);
            switch (c) {
            case 216:;
            {
            }break;
            case 224:;
            {
            }break;
            case 225:;
            case 226:;
            case 227:;
            case 228:;
            case 229:;
            case 230:;
            case 231:;
            case 232:;
            case 233:;
            case 234:;
            case 235:;
            case 236:;
            case 237:;
            case 239:;
            {
                jpeg_readapp(fs,(c - (i64)224));
            }break;
            case 192:;
            {
                jpeg_read_sof(fs);
            }break;
            case 194:;
            {
            }break;
            case 196:;
            {
                jpeg_read_dht(fs);
            }break;
            case 219:;
            {
                jpeg_read_dqt(fs);
            }break;
            case 221:;
            {
                jpeg_readword(fs);
                jpeg_hdr.dri = jpeg_readword(fs);
            }break;
            case 238:;
            {
            }break;
            case 218:;
            {
                jpeg_read_sos(fs);
                pimage = jpeg_loadscan(fs);
                goto L72 ;
            }break;
            case 217:;
            {
            }break;
            case 0:;
            {
            }break;
            case 255:;
            {
            }break;
            default: {
            }
            } //SW
;
        };
    }L72 :;
    ;
    return pimage;
}

static byte * jpeg_loadscan(struct jpeg_stream * fs) {
    byte *  pimage;
    jpeg_initbitstream(fs);
    pimage = (byte *)(0);
    if ((jpeg_hdr.ncomponents==(i64)1)) {
        jpeg_abortjpeg((byte*)"loadmono");
    }else if ((jpeg_hdr.ncomponents==(i64)3)) {
        if ((((jpeg_hdr.comptype[((i64)1)-1] != (i64)1) || (jpeg_hdr.comptype[((i64)2)-1] != (i64)2)) || (jpeg_hdr.comptype[((i64)3)-1] != (i64)3))) {
            jpeg_abortjpeg((byte*)"comptype?");
        };
        if (((((jpeg_hdr.hsample[((i64)2)-1] == jpeg_hdr.vsample[((i64)2)-1]) && (jpeg_hdr.vsample[((i64)2)-1] == jpeg_hdr.hsample[((i64)3)-1])) && (jpeg_hdr.hsample[((i64)3)-1] == jpeg_hdr.vsample[((i64)3)-1])) && ((jpeg_hdr.hsample[((i64)1)-1] <= (i64)2) && (jpeg_hdr.vsample[((i64)1)-1] <= (i64)2)))) {
            pimage = jpeg_loadcolour(fs,jpeg_hdr.hsample[((i64)1)-1],jpeg_hdr.vsample[((i64)1)-1]);
        } else {
            msysnewc_m_print_startcon();
            msysnewc_m_print_i64(jpeg_hdr.hsample[((i64)1)-1],NULL);
            msysnewc_m_print_i64(jpeg_hdr.vsample[((i64)1)-1],NULL);
            msysnewc_m_print_i64(jpeg_hdr.hsample[((i64)2)-1],NULL);
            msysnewc_m_print_i64(jpeg_hdr.vsample[((i64)2)-1],NULL);
            msysnewc_m_print_i64(jpeg_hdr.hsample[((i64)3)-1],NULL);
            msysnewc_m_print_i64(jpeg_hdr.vsample[((i64)3)-1],NULL);
            msysnewc_m_print_newline();
            msysnewc_m_print_end();
            ;
            jpeg_abortjpeg((byte*)"LOAD COLOUR/Unknown sampling");
        };
    } else {
        jpeg_abortjpeg((byte*)"ncomp");
    };
    return pimage;
}

static i64 jpeg_tree_getsymbol(struct jpeg_stream * fs,struct jpeg_huffnode * node) {
    i64 av_1;
    L73 :;
    while (!!((*node).child0)) {
        if (!!(jpeg_nextbit(fs))) {
            node = (*node).child1;
        } else {
            node = (*node).child0;
        };
L74 :;
    }L75 :;
    ;
    av_1 = (*node).suppbits;
    while (av_1-- > 0) {
L76 :;
        jpeg_nextbit(fs);
L77 :;
    }L78 :;
    ;
    return (*node).symbol;
}

static i64 jpeg_getsymbol(struct jpeg_stream * fs,i64 nbits) {
    i64 a;
    i64 b;
    i64 av_1;
    if ((nbits == (i64)0)) {
        return (i64)0;
    };
    a = (i64)0;
    av_1 = nbits;
    while (av_1-- > 0) {
L79 :;
        a <<= (i64)1;
        b = jpeg_nextbit(fs);
        a |= b;
L80 :;
    }L81 :;
    ;
    if (((a & ((i64)1 << (nbits - (i64)1))) == (i64)0)) {
        a -= (((i64)1 << nbits) - (i64)1);
    };
    return a;
}

static void jpeg_unzigzag(i64 (*block)[64]) {
    static i64 zigzag[64] = {
    (i64)1,
    (i64)2,
    (i64)6,
    (i64)7,
    (i64)15,
    (i64)16,
    (i64)28,
    (i64)29,
    (i64)3,
    (i64)5,
    (i64)8,
    (i64)14,
    (i64)17,
    (i64)27,
    (i64)30,
    (i64)43,
    (i64)4,
    (i64)9,
    (i64)13,
    (i64)18,
    (i64)26,
    (i64)31,
    (i64)42,
    (i64)44,
    (i64)10,
    (i64)12,
    (i64)19,
    (i64)25,
    (i64)32,
    (i64)41,
    (i64)45,
    (i64)54,
    (i64)11,
    (i64)20,
    (i64)24,
    (i64)33,
    (i64)40,
    (i64)46,
    (i64)53,
    (i64)55,
    (i64)21,
    (i64)23,
    (i64)34,
    (i64)39,
    (i64)47,
    (i64)52,
    (i64)56,
    (i64)61,
    (i64)22,
    (i64)35,
    (i64)38,
    (i64)48,
    (i64)51,
    (i64)57,
    (i64)60,
    (i64)62,
    (i64)36,
    (i64)37,
    (i64)49,
    (i64)50,
    (i64)58,
    (i64)59,
    (i64)63,
    (i64)64
};
    i64 temp[64];
    i64 i;
    memcpy(&temp,block,512);
    L82 :;
    for (i=(i64)1;i<=(i64)64;i+=(i64)1) {
L83 :;
        (*block)[(i)-1] = temp[(zigzag[(i)-1])-1];
L84 :;
    }L85 :;
    ;
}

static void jpeg_idct8x8(i64 (*block)[]) {
    i64 j;
    i64 i;
    L86 :;
    for (i=(i64)0;i<=(i64)7;i+=(i64)1) {
L87 :;
        j = ((i * (i64)8) + (i64)1);
        jpeg_fastidct8(&(*block)[(j)-1],&(*block)[((j + (i64)1))-1],&(*block)[((j + (i64)2))-1],&(*block)[((j + (i64)3))-1],&(*block)[((j + (i64)4))-1],&(*block)[((j + (i64)5))-1],&(*block)[((j + (i64)6))-1],&(*block)[((j + (i64)7))-1]);
L88 :;
    }L89 :;
    ;
    L90 :;
    for (i=(i64)1;i<=(i64)64;i+=(i64)1) {
L91 :;
        (*block)[(i)-1] >>= (i64)3;
L92 :;
    }L93 :;
    ;
    L94 :;
    for (i=(i64)1;i<=(i64)8;i+=(i64)1) {
L95 :;
        jpeg_fastidct8(&(*block)[(i)-1],&(*block)[((i + (i64)8))-1],&(*block)[((i + (i64)16))-1],&(*block)[((i + (i64)24))-1],&(*block)[((i + (i64)32))-1],&(*block)[((i + (i64)40))-1],&(*block)[((i + (i64)48))-1],&(*block)[((i + (i64)56))-1]);
L96 :;
    }L97 :;
    ;
}

static void jpeg_fastidct8(i64 * a1,i64 * a2,i64 * a3,i64 * a4,i64 * a5,i64 * a6,i64 * a7,i64 * a8) {
    i64 x1;
    i64 x2;
    i64 x3;
    i64 x4;
    i64 x5;
    i64 x6;
    i64 x7;
    i64 x8;
    i64 x9;
    if (!(!!((((((((x2 = ((*a5) << (i64)11)) | (x3 = (*a7))) | (x4 = (*a3))) | (x5 = (*a2))) | (x6 = (*a8))) | (x7 = (*a6))) | (x8 = (*a4)))))) {
        (*a1) = ((*a2) = ((*a3) = ((*a4) = ((*a5) = ((*a6) = ((*a7) = ((*a8) = ((*a1) << (i64)3))))))));
        return;
    };
    x1 = (((*a1) << (i64)11) + (i64)128);
    x9 = ((i64)565 * (x5 + x6));
    x5 = (x9 + ((i64)2276 * x5));
    x6 = (x9 - ((i64)3406 * x6));
    x9 = ((i64)2408 * (x7 + x8));
    x7 = (x9 - ((i64)799 * x7));
    x8 = (x9 - ((i64)4017 * x8));
    x9 = (x1 + x2);
    x1 -= x2;
    x2 = ((i64)1108 * (x4 + x3));
    x3 = (x2 - ((i64)3784 * x3));
    x4 = (x2 + ((i64)1568 * x4));
    x2 = (x5 + x7);
    x5 -= x7;
    x7 = (x6 + x8);
    x6 -= x8;
    x8 = (x9 + x4);
    x9 -= x4;
    x4 = (x1 + x3);
    x1 -= x3;
    x3 = ((((i64)181 * (x5 + x6)) + (i64)128) >> (i64)8);
    x5 = ((((i64)181 * (x5 - x6)) + (i64)128) >> (i64)8);
    (*a1) = ((x8 + x2) >> (i64)8);
    (*a2) = ((x4 + x3) >> (i64)8);
    (*a3) = ((x1 + x5) >> (i64)8);
    (*a4) = ((x9 + x7) >> (i64)8);
    (*a5) = ((x9 - x7) >> (i64)8);
    (*a6) = ((x1 - x5) >> (i64)8);
    (*a7) = ((x4 - x3) >> (i64)8);
    (*a8) = ((x8 - x2) >> (i64)8);
}

static void jpeg_getblock(struct jpeg_stream * fs,struct jpeg_huffnode * dctree,struct jpeg_huffnode * actree,i64 (*block)[]) {
    i64 nbits;
    i64 nread;
    i64 bb;
    i64 zeroes;
    nbits = jpeg_tree_getsymbol(fs,dctree);
    nread = (i64)0;
    ++nread;
    memset((void *)(block),(i64)0,(u64)((i64)512));
    (*block)[(nread)-1] = jpeg_getsymbol(fs,nbits);
    L98 :;
    do {
        bb = jpeg_tree_getsymbol(fs,actree);
        if ((bb == (i64)240)) {
            if ((nread > (i64)48)) {
                jpeg_abortjpeg((byte*)"GETB1");
            };
            nread += (i64)16;
        };
        zeroes = (bb >> (i64)4);
        nbits = (bb & (i64)15);
        if (!!(nbits)) {
            if (((nread + zeroes) > (i64)63)) {
                jpeg_abortjpeg((byte*)"nzeroes");
            };
            nread += zeroes;
            ++nread;
            (*block)[(nread)-1] = jpeg_getsymbol(fs,nbits);
            if ((nread == (i64)64)) {
                return;
            };
        };
L99 :;
    } while (!!(!!(bb)));L100 :;
    ;
}

static void jpeg_readblock(struct jpeg_stream * fs,i64 (*block)[],struct jpeg_huffnode * dctable,struct jpeg_huffnode * actable,i64 (*qtable)[],i64 * dc) {
    i64 u;
    i64 k;
    jpeg_getblock(fs,dctable,actable,block);
    (*block)[((i64)1)-1] = ((*block)[((i64)1)-1] + (*dc));
    (*dc) = (*block)[((i64)1)-1];
    u = jpeg_hdr.useq[((i64)2)-1];
    L101 :;
    for (k=(i64)1;k<=(i64)64;k+=(i64)1) {
L102 :;
        (*block)[(k)-1] *= (*qtable)[(k)-1];
L103 :;
    }L104 :;
    ;
    jpeg_unzigzag(block);
    jpeg_idct8x8(block);
}

static byte * jpeg_loadcolour(struct jpeg_stream * fs,i64 hoz,i64 vert) {
    i64 x;
    i64 y;
    i64 nlum;
    i64 count;
    i64 j;
    i64 diffdc;
    i64 dcr;
    i64 dcb;
    byte *  data;
    struct jpeg_huffnode *  dctable_lum;
    struct jpeg_huffnode *  actable_lum;
    struct jpeg_huffnode *  dctable_cb;
    struct jpeg_huffnode *  actable_cb;
    struct jpeg_huffnode *  dctable_cr;
    struct jpeg_huffnode *  actable_cr;
    i64 (*qtable_lum)[];
    i64 (*qtable_cb)[];
    i64 (*qtable_cr)[];
    i64 cr[64];
    i64 cb[64];
    i64 lum[4][64];
    data = (byte *)(jpeg_jallocz(jpeg_hdr.framebytes));
    diffdc = (dcb = (dcr = (i64)0));
    nlum = (hoz * vert);
    dctable_lum = jpeg_hdr.dctable[(jpeg_hdr.usedc[((i64)1)-1])-1];
    actable_lum = jpeg_hdr.actable[(jpeg_hdr.useac[((i64)1)-1])-1];
    qtable_lum = &jpeg_hdr.qtable[(jpeg_hdr.useq[((i64)1)-1])-1];
    dctable_cb = jpeg_hdr.dctable[(jpeg_hdr.usedc[((i64)2)-1])-1];
    actable_cb = jpeg_hdr.actable[(jpeg_hdr.useac[((i64)2)-1])-1];
    qtable_cb = &jpeg_hdr.qtable[(jpeg_hdr.useq[((i64)2)-1])-1];
    dctable_cr = jpeg_hdr.dctable[(jpeg_hdr.usedc[((i64)3)-1])-1];
    actable_cr = jpeg_hdr.actable[(jpeg_hdr.useac[((i64)3)-1])-1];
    qtable_cr = &jpeg_hdr.qtable[(jpeg_hdr.useq[((i64)3)-1])-1];
    count = (i64)0;
    y = (i64)0;
    L105 :;
    while ((y < jpeg_hdr.height)) {
        x = (i64)0;
        L108 :;
        while ((x < jpeg_hdr.width)) {
            if (((!!(jpeg_hdr.dri) && ((count % jpeg_hdr.dri) == (i64)0)) && (count > (i64)0))) {
                jpeg_readmarker(fs);
                diffdc = (i64)0;
                dcb = (dcr = (i64)0);
            };
            L111 :;
            for (j=(i64)1;j<=nlum;j+=(i64)1) {
L112 :;
                jpeg_readblock(fs,&lum[(j)-1],dctable_lum,actable_lum,qtable_lum,&diffdc);
L113 :;
            }L114 :;
            ;
            jpeg_readblock(fs,&cb,dctable_cb,actable_cb,qtable_cb,&dcb);
            jpeg_readblock(fs,&cr,dctable_cr,actable_cr,qtable_cr,&dcr);
            jpeg_reconsblockcolour(&lum[((i64)1)-1],&lum[((i64)2)-1],&lum[((i64)3)-1],&lum[((i64)4)-1],&cr,&cb,data,x,y,hoz,vert);
            ++count;
            x += (hoz * (i64)8);
L109 :;
        }L110 :;
        ;
        y += (vert * (i64)8);
L106 :;
    }L107 :;
    ;
    jpeg_read_eoi(fs);
    return data;
}

static void jpeg_reconsblockcolour(i64 (*lum1)[],i64 (*lum2)[],i64 (*lum3)[],i64 (*lum4)[],i64 (*cr)[],i64 (*cb)[],byte * data,i64 x,i64 y,i64 hoz,i64 vert) {
    i64 width;
    i64 height;
    i64 ilim;
    i64 jlim;
    i64 i;
    i64 j;
    i64 yy;
    i64 ix;
    i64 rr;
    i64 bb;
    i64 luminance;
    byte *  p;
    width = jpeg_hdr.width;
    height = jpeg_hdr.height;
    ilim = ((vert * (i64)8) - (i64)1);
    jlim = ((hoz * (i64)8) - (i64)1);
    L115 :;
    for (i=(i64)0;i<=ilim;i+=(i64)1) {
L116 :;
        if (((yy = (y + i)) >= height)) {
            goto L117 ;
        };
        p = (data + (((yy * width) + x) * (i64)3));
        L119 :;
        for (j=(i64)0;j<=jlim;j+=(i64)1) {
L120 :;
            if (((x + j) >= width)) {
                goto L121 ;
            };
            if ((i < (i64)8)) {
                if ((j < (i64)8)) {
                    luminance = (((*lum1)[((((i * (i64)8) + j) + (i64)1))-1] / (i64)64) + (i64)128);
                } else {
                    luminance = (((*lum2)[(((((i * (i64)8) + j) - (i64)8) + (i64)1))-1] / (i64)64) + (i64)128);
                };
            } else {
                if ((j < (i64)8)) {
                    luminance = (((*lum3)[(((((i - (i64)8) * (i64)8) + j) + (i64)1))-1] / (i64)64) + (i64)128);
                } else {
                    luminance = (((*lum4)[((((((i - (i64)8) * (i64)8) + j) - (i64)8) + (i64)1))-1] / (i64)64) + (i64)128);
                };
            };
            ix = ((((i / vert) * (i64)8) + (j >> (i64)1)) + (i64)1);
            rr = (*cr)[(ix)-1];
            bb = (*cb)[(ix)-1];
            (*p) = (u64)(msysnewc_m_imin(msysnewc_m_imax((((bb * (i64)57) / (i64)2048) + luminance),(i64)0),(i64)255));
            ++p;
            (*p) = (u64)(msysnewc_m_imin(msysnewc_m_imax((luminance - (((bb * (i64)11) + (rr * (i64)23)) / (i64)2048)),(i64)0),(i64)255));
            ++p;
            (*p) = (u64)(msysnewc_m_imin(msysnewc_m_imax((((rr * (i64)45) / (i64)2048) + luminance),(i64)0),(i64)255));
            ++p;
L121 :;
        }L122 :;
        ;
L117 :;
    }L118 :;
    ;
}

static void * jpeg_jalloc(i64 n) {
    void *  p;
    p = malloc((u64)(n));
    if ((p == 0)) {
        msysnewc_m_print_startcon();
        msysnewc_m_print_str((byte*)"JPEG MALLOC FAILS",NULL);
        msysnewc_m_print_newline();
        msysnewc_m_print_end();
        ;
        exit(0);
    };
    return p;
}

static void * jpeg_jallocz(i64 n) {
    void *  p;
    p = jpeg_jalloc(n);
    memset(p,(i64)0,(u64)(n));
    return p;
}

static void jpeg_abortjpeg(byte * mess) {
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"Jpeg error:",NULL);
    msysnewc_m_print_str(mess,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    exit(0);
}

void * mlib_pcm_alloc(i64 n) {
    byte *  p;
    if (!(!!((u64)(mlib_pcm_setup)))) {
        mlib_pcm_init();
    };
    if ((n > (i64)2048)) {
        mlib_alloccode = mlib_pcm_getac(n);
        mlib_allocbytes = (i64)(mlib_allocupper[(mlib_alloccode)]);
        p = (byte *)(mlib_allocmem(mlib_allocbytes));
        if (!(!!(p))) {
            mlib_abortprogram((byte*)"pcm_alloc failure");
        };
        if (!!((i64)0)) {
            mlib_addtomemalloc((i32 *)(p),mlib_allocbytes);
        };
        return (void *)(p);
    };
    mlib_alloccode = (i64)(mlib_sizeindextable[(n)]);
    if ((mlib_alloccode == (i64)0)) {
        mlib_alloccode = (i64)1;
    };
    mlib_allocbytes = (i64)(mlib_allocupper[(mlib_alloccode)]);
    mlib_smallmemtotal += mlib_allocbytes;
    if (!!((p = (byte *)(mlib_freelist[(mlib_alloccode)])))) {
        if (!!((i64)0)) {
            mlib_addtomemalloc((i32 *)(p),mlib_allocbytes);
        };
        mlib_freelist[(mlib_alloccode)] = (u64 *)((i64)((*mlib_freelist[(mlib_alloccode)])));
        return (void *)(p);
    };
    p = mlib_pcheapptr;
    mlib_pcheapptr += mlib_allocbytes;
    if ((mlib_pcheapptr >= mlib_pcheapend)) {
        p = (byte *)(mlib_pcm_newblock(mlib_allocbytes));
        return (void *)(p);
    };
    if (!!((i64)0)) {
        mlib_addtomemalloc((i32 *)(p),mlib_allocbytes);
    };
    return (void *)(p);
}

void mlib_pcm_freestr(byte * s) {
    mlib_pcm_free((void *)(s),((i64)(strlen((i8 *)(s))) + (i64)1));
}

void mlib_pcm_free(void * p,i64 n) {
    i64 acode;
    if ((n == (i64)0)) {
        return;
    };
    if ((n > (i64)2048)) {
        if (!!((i64)0)) {
            mlib_removefrommemalloc((i32 *)(p),n);
        };
        free(p);
        return;
    };
    if (!!(p)) {
        acode = (i64)(mlib_sizeindextable[(n)]);
        mlib_smallmemtotal -= (i64)(mlib_allocupper[(acode)]);
        if (!!((i64)0)) {
            mlib_removefrommemalloc((i32 *)(p),(i64)(mlib_allocupper[(acode)]));
        };
        (*(u64 *)(p)) = (u64)((i64)(mlib_freelist[(acode)]));
        mlib_freelist[(acode)] = (u64 *)(p);
    };
}

void mlib_pcm_freeac(void * p,i64 alloc) {
    mlib_pcm_free(p,(i64)(mlib_allocupper[(alloc)]));
}

void mlib_pcm_copymem4(void * p,void * q,i64 n) {
    memcpy(p,q,(u64)(n));
}

void mlib_pcm_clearmem(void * p,i64 n) {
    memset(p,(i64)0,(u64)(n));
}

void mlib_pcm_init(void) {
    i64 j;
    i64 k;
    i64 size;
    i64 av_1;
    i64 i;
    if (!!((u64)(mlib_pcm_setup))) {
        return;
    };
    mlib_pcm_newblock((i64)0);
    L123 :;
    for (i=(i64)1;i<=(i64)2048;i+=(i64)1) {
L124 :;
        j = (i64)1;
        k = (i64)16;
        L127 :;
        while ((i > k)) {
            k = (k << (i64)1);
            ++j;
L128 :;
        }L129 :;
        ;
        mlib_sizeindextable[(i)] = (u64)(j);
L125 :;
    }L126 :;
    ;
    mlib_allocupper[((i64)1)] = (u64)((i64)16);
    size = (i64)16;
    L130 :;
    for (i=(i64)2;i<=(i64)27;i+=(i64)1) {
L131 :;
        size *= (i64)2;
        mlib_allocupper[(i)] = (u64)(size);
        if ((size >= (i64)33554432)) {
            k = i;
            goto L133 ;
        };
L132 :;
    }L133 :;
    ;
    L134 :;
    for (i=(k + (i64)1);i<=(i64)300;i+=(i64)1) {
L135 :;
        size += (i64)33554432;
        if ((size < (i64)8589934592)) {
            mlib_allocupper[(i)] = (u64)(size);
            mlib_maxmemory = (u64)(size);
        } else {
            mlib_maxalloccode = (i - (i64)1);
            goto L137 ;
        };
L136 :;
    }L137 :;
    ;
    mlib_pcm_setup = (u64)((i64)1);
}

i64 mlib_pcm_getac(i64 size) {
    if ((size <= (i64)2048)) {
        return (i64)(mlib_sizeindextable[(size)]);
    };
    size = ((size + (i64)255) >> (i64)8);
    if ((size <= (i64)2048)) {
        return ((i64)((u64)(mlib_sizeindextable[(size)])) + (i64)8);
    };
    size = ((size + (i64)63) >> (i64)6);
    if ((size <= (i64)2048)) {
        return ((i64)((u64)(mlib_sizeindextable[(size)])) + (i64)14);
    };
    size = ((((size - (i64)2048) + (i64)2047) / (i64)2048) + (i64)22);
    return size;
}

void * mlib_pcm_newblock(i64 itemsize) {
    static i64 totalheapsize;
    byte *  p;
    totalheapsize += (i64)2097152;
    mlib_alloccode = (i64)0;
    p = (byte *)(mlib_allocmem((i64)2097152));
    if ((p == 0)) {
        mlib_abortprogram((byte*)"Can't alloc pc heap");
    };
    mlib_pcheapptr = p;
    mlib_pcheapend = (p + (i64)2097152);
    if ((mlib_pcheapstart == 0)) {
        mlib_pcheapstart = p;
    };
    mlib_pcheapptr += itemsize;
    return (void *)((u32 *)(p));
}

i64 mlib_pcm_round(i64 n) {
    static i32 allocbytes[9] = {(i32)0,(i32)16,(i32)32,(i32)64,(i32)128,(i32)256,(i32)512,(i32)1024,(i32)2048};
    if ((n > (i64)2048)) {
        return n;
    } else {
        return (i64)(allocbytes[((i64)(mlib_sizeindextable[(n)]))]);
    };
}

i64 mlib_pcm_array(i64 n) {
    i64 m;
    if ((n <= (i64)2048)) {
        return mlib_pcm_round(n);
    } else {
        m = (i64)2048;
        L138 :;
        while ((n > m)) {
            m <<= (i64)1;
L139 :;
        }L140 :;
        ;
        return m;
    };
}

void mlib_pcm_printfreelist(i64 size,u64 * p) {
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"Size: ",NULL);
    msysnewc_m_print_i64(size,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    L141 :;
    while (!!(p)) {
        msysnewc_m_print_startcon();
        msysnewc_m_print_str((byte*)" ",NULL);
        msysnewc_m_print_nogap();
        msysnewc_m_print_ptr(p,(byte*)"h");
        msysnewc_m_print_end();
        ;
        p = (u64 *)((i64)((*p)));
L142 :;
    }L143 :;
    ;
    puts((i8 *)((byte*)""));
}

void mlib_pcm_diags(byte * caption) {
    i64 m;
    i64 i;
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"HEAP FREELISTS:",NULL);
    msysnewc_m_print_str(caption,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    m = (i64)16;
    L144 :;
    for (i=(i64)1;i<=(i64)8;i+=(i64)1) {
L145 :;
        mlib_pcm_printfreelist(m,mlib_freelist[(i)]);
        m <<= (i64)1;
L146 :;
    }L147 :;
    ;
}

void * mlib_pcm_allocz(i64 n) {
    void *  p;
    p = mlib_pcm_alloc(n);
    memset(p,(i64)0,(u64)(n));
    return p;
}

byte * mlib_pcm_copyheapstring(byte * s) {
    byte *  q;
    i64 n;
    if ((s == 0)) {
        return (byte *)(0);
    };
    n = ((i64)(strlen((i8 *)(s))) + (i64)1);
    q = (byte *)(mlib_pcm_alloc(n));
    memcpy((void *)(q),(void *)(s),(u64)(n));
    return q;
}

byte * mlib_pcm_copyheapstringn(byte * s,i64 n) {
    byte *  q;
    if ((s == 0)) {
        return (byte *)(0);
    };
    q = (byte *)(mlib_pcm_alloc((n + (i64)1)));
    memcpy((void *)(q),(void *)(s),(u64)(n));
    (*(q + n)) = (u64)0u;
    return q;
}

byte * mlib_pcm_copyheapblock(byte * s,i64 length) {
    byte *  q;
    if ((length == (i64)0)) {
        return (byte *)(0);
    };
    q = (byte *)(mlib_pcm_alloc(length));
    memcpy((void *)(q),(void *)(s),(u64)(length));
    return q;
}

static void mlib_addtomemalloc(i32 * ptr,i64 size) {
    i64 i;
    L148 :;
    for (i=(i64)1;i<=(i64)500000;i+=(i64)1) {
L149 :;
        if ((mlib_memalloctable[(i)-1] == ptr)) {
            msysnewc_m_print_startcon();
            msysnewc_m_print_str((byte*)"ALLOC ERROR:",NULL);
            msysnewc_m_print_ptr(ptr,NULL);
            msysnewc_m_print_str((byte*)"ALREADY ALLOCATED\n\n\n",NULL);
            msysnewc_m_print_newline();
            msysnewc_m_print_end();
            ;
            msysnewc_m_print_startcon();
            msysnewc_m_print_newline();
            msysnewc_m_print_end();
            ;
            msysnewc_m_print_startcon();
            msysnewc_m_print_newline();
            msysnewc_m_print_end();
            ;
            exit((i64)2);
        };
        if ((mlib_memalloctable[(i)-1] == 0)) {
            mlib_memalloctable[(i)-1] = ptr;
            mlib_memallocsize[(i)-1] = size;
            return;
        };
L150 :;
    }L151 :;
    ;
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"MEMALLOCTABLE FULL\n\n\n\n",NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    oswindows_os_getch();
    exit((i64)3);
}

static void mlib_removefrommemalloc(i32 * ptr,i64 size) {
    i64 i;
    L152 :;
    for (i=(i64)1;i<=(i64)500000;i+=(i64)1) {
L153 :;
        if ((mlib_memalloctable[(i)-1] == ptr)) {
            if (((i64)(mlib_memallocsize[(i)-1]) != size)) {
                msysnewc_m_print_startcon();
                msysnewc_m_print_str((byte*)"REMOVE:FOUND",NULL);
                msysnewc_m_print_ptr(ptr,NULL);
                msysnewc_m_print_str((byte*)"IN MEMALLOCTABLE, FREESIZE=",NULL);
                msysnewc_m_print_i64(size,NULL);
                msysnewc_m_print_str((byte*)", BUT STORED AS BLOCK SIZE:",NULL);
                msysnewc_m_print_i64(mlib_memallocsize[(i)-1],NULL);
                msysnewc_m_print_newline();
                msysnewc_m_print_end();
                ;
                msysnewc_m_print_startcon();
                msysnewc_m_print_newline();
                msysnewc_m_print_end();
                ;
                msysnewc_m_print_startcon();
                msysnewc_m_print_newline();
                msysnewc_m_print_end();
                ;
                mlib_abortprogram((byte*)"MEMSIZE");
            };
            mlib_memalloctable[(i)-1] = (i32 *)(0);
            return;
        };
L154 :;
    }L155 :;
    ;
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"CAN'T FIND",NULL);
    msysnewc_m_print_ptr(ptr,NULL);
    msysnewc_m_print_str((byte*)"IN MEMALLOCTABLE",NULL);
    msysnewc_m_print_i64(size,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    msysnewc_m_print_startcon();
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    msysnewc_m_print_startcon();
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    mlib_abortprogram((byte*)"MEM");
    exit((i64)4);
}

void * mlib_allocmem(i64 n) {
    void *  p;
    p = malloc((u64)(n));
    if (!!(p)) {
        return p;
    };
    msysnewc_m_print_startcon();
    msysnewc_m_print_i64(n,NULL);
    msysnewc_m_print_i64(mlib_memtotal,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    mlib_abortprogram((byte*)"Alloc mem failure");
    return 0;
}

void * mlib_reallocmem(void * p,i64 n) {
    p = realloc(p,(u64)(n));
    if (!!(p)) {
        return p;
    };
    msysnewc_m_print_startcon();
    msysnewc_m_print_i64(n,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    mlib_abortprogram((byte*)"Realloc mem failure");
    return 0;
}

void mlib_abortprogram(byte * s) {
    msysnewc_m_print_startcon();
    msysnewc_m_print_str(s,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"ABORTING: Press key...",NULL);
    msysnewc_m_print_end();
    ;
    oswindows_os_getch();
    exit((i64)5);
}

i64 mlib_getfilesize(void * handlex) {
    u32 p;
    u32 size;
    p = (u64)(ftell(handlex));
    fseek(handlex,(i64)0,(i64)2);
    size = (u64)(ftell(handlex));
    fseek(handlex,(i64)((i32)(p)),(i64)0);
    return (i64)(size);
}

void mlib_readrandom(void * handlex,byte * mem,i64 offset,i64 size) {
    i64 a;
    fseek(handlex,(i64)((i32)(offset)),(i64)0);
    a = (i64)(fread((void *)(mem),(u64)((i64)1),(u64)(size),handlex));
}

i64 mlib_writerandom(void * handlex,byte * mem,i64 offset,i64 size) {
    fseek(handlex,(i64)((i32)(offset)),(i64)0);
    return (i64)(fwrite((void *)(mem),(u64)((i64)1),(u64)(size),handlex));
}

i64 mlib_setfilepos(void * file,i64 offset) {
    return (i64)(fseek(file,(i64)((i32)(offset)),(i64)0));
}

i64 mlib_getfilepos(void * file) {
    return (i64)(ftell(file));
}

byte * mlib_readfile(byte * filename) {
    void *  f;
    i64 size;
    byte *  m;
    byte *  p;
    f = fopen((i8 *)(filename),(i8 *)((byte*)"rb"));
    if ((f == 0)) {
        return (byte *)(0);
    };
    mlib_rfsize = (size = mlib_getfilesize(f));
    m = (byte *)(malloc((u64)((size + (i64)4))));
    if ((m == 0)) {
        return (byte *)(0);
    };
    mlib_readrandom(f,m,(i64)0,size);
    p = (m + size);
    (*p) = (u64)((i64)0);
    (*(p + (i64)1)) = (u64)((i64)26);
    (*(p + (i64)2)) = (u64)((i64)0);
    fclose(f);
    return m;
}

i64 mlib_writefile(byte * filename,byte * data,i64 size) {
    void *  f;
    i64 n;
    f = fopen((i8 *)(filename),(i8 *)((byte*)"wb"));
    if ((f == 0)) {
        return (i64)0;
    };
    n = mlib_writerandom(f,data,(i64)0,size);
    fclose(f);
    return n;
}

i64 mlib_checkfile(byte * file) {
    void *  f;
    if (!!((f = fopen((i8 *)(file),(i8 *)((byte*)"rb"))))) {
        fclose(f);
        return (i64)1;
    };
    return (i64)0;
}

void mlib_readlinen(void * handlex,byte * buffer,i64 size) {
    i64 ch;
    byte *  p;
    i64 n;
    byte crseen;
    if ((handlex == 0)) {
        handlex = oswindows_os_getstdin();
    };
    if ((handlex == 0)) {
        n = (i64)0;
        p = buffer;
        L156 :;
        while (1) {
            ch = (i64)(getchar());
            if ((((ch == (i64)13) || (ch == (i64)10)) || (ch == (i64)-1))) {
                (*p) = (u64)0u;
                return;
            };
            (*p++) = (u64)(ch);
            ++n;
            if ((n >= (size - (i64)2))) {
                (*p) = (u64)0u;
                return;
            };
        }L157 :;
        ;
    };
    (*buffer) = (u64)0u;
    if ((fgets((i8 *)(buffer),(size - (i64)2),handlex) == 0)) {
        return;
    };
    n = (i64)(strlen((i8 *)(buffer)));
    if ((n == (i64)0)) {
        return;
    };
    p = ((buffer + n) - (i64)1);
    crseen = (u64)((i64)0);
    L158 :;
    while (((p >= buffer) && (((i64)((*p)) == (i64)13) || ((i64)((*p)) == (i64)10)))) {
        if ((((i64)((*p)) == (i64)13) || ((i64)((*p)) == (i64)10))) {
            crseen = (u64)((i64)1);
        };
        (*p--) = (u64)0u;
L159 :;
    }L160 :;
    ;
    if ((!(!!((u64)(crseen))) && ((n + (i64)4) > size))) {
        msysnewc_m_print_startcon();
        msysnewc_m_print_i64(size,NULL);
        msysnewc_m_print_i64(n,NULL);
        msysnewc_m_print_newline();
        msysnewc_m_print_end();
        ;
        mlib_abortprogram((byte*)"line too long");
    };
}

void mlib_iconvlcn(byte * s,i64 n) {
    i64 av_1;
    av_1 = n;
    while (av_1-- > 0) {
L161 :;
        (*s) = (u64)(tolower((i64)((i32)((*s)))));
        ++s;
L162 :;
    }L163 :;
    ;
}

void mlib_iconvucn(byte * s,i64 n) {
    i64 av_1;
    av_1 = n;
    while (av_1-- > 0) {
L164 :;
        (*s) = (u64)(toupper((i64)((i32)((*s)))));
        ++s;
L165 :;
    }L166 :;
    ;
}

void mlib_convlcstring(byte * s) {
    L167 :;
    while (!!((u64)((*s)))) {
        (*s) = (u64)(tolower((i64)((i32)((*s)))));
        ++s;
L168 :;
    }L169 :;
    ;
}

void mlib_convucstring(byte * s) {
    L170 :;
    while (!!((u64)((*s)))) {
        (*s) = (u64)(toupper((i64)((i32)((*s)))));
        ++s;
L171 :;
    }L172 :;
    ;
}

byte * mlib_changeext(byte * s,byte * newext) {
    static byte newfile[260];
    byte newext2[32];
    byte *  sext;
    i64 n;
    strcpy((i8 *)(&newfile[((i64)1)-1]),(i8 *)(s));
    if (((i64)((*newext))==(i64)0)) {
        newext2[((i64)1)-1] = (u64)0u;
        newext2[((i64)2)-1] = (u64)0u;
    }else if (((i64)((*newext))==(i64)46)) {
        strcpy((i8 *)(&newext2[((i64)1)-1]),(i8 *)(newext));
    } else {
        strcpy((i8 *)(&newext2[((i64)1)-1]),(i8 *)((byte*)"."));
        strcat((i8 *)(&newext2[((i64)1)-1]),(i8 *)(newext));
    };
    sext = mlib_extractext(s,(i64)1);
    if (((i64)((*sext))==(i64)0)) {
        strcat((i8 *)(&newfile[((i64)1)-1]),(i8 *)(&newext2[((i64)1)-1]));
    }else if (((i64)((*sext))==(i64)46)) {
        strcat((i8 *)(&newfile[((i64)1)-1]),(i8 *)(&newext2[((i64)2)-1]));
    } else {
        n = ((sext - s) - (i64)2);
        strcpy((i8 *)(((&newfile[((i64)1)-1] + n) + (i64)1)),(i8 *)(&newext2[((i64)1)-1]));
    };
    return &newfile[((i64)1)-1];
}

byte * mlib_extractext(byte * s,i64 period) {
    byte *  t;
    byte *  u;
    t = mlib_extractfile(s);
    if (((i64)((*t)) == (i64)0)) {
        return (byte*)"";
    };
    u = ((t + (i64)(strlen((i8 *)(t)))) - (i64)1);
    L173 :;
    while ((u >= t)) {
        if (((u64)((*u)) == '.')) {
            if (((i64)((*(u + (i64)1))) == (i64)0)) {
                return (!!(period)?(byte*)".":(byte*)"");
            };
            return (u + (i64)1);
        };
        --u;
L174 :;
    }L175 :;
    ;
    return (byte*)"";
}

byte * mlib_extractpath(byte * s) {
    static byte str[260];
    byte *  t;
    i64 n;
    t = ((s + (i64)(strlen((i8 *)(s)))) - (i64)1);
    L176 :;
    while ((t >= s)) {
        switch ((i64)((*t))) {
        case 92:;
        case 47:;
        case 58:;
        {
            n = ((t - s) + (i64)1);
            memcpy((void *)(str),(void *)(s),(u64)(n));
            str[(n)] = (u64)0u;
            return str;
        }break;
        default: {
        }
        } //SW
;
        --t;
L177 :;
    }L178 :;
    ;
    return (byte*)"";
}

byte * mlib_extractfile(byte * s) {
    byte *  t;
    t = mlib_extractpath(s);
    if (((i64)((*t)) == (i64)0)) {
        return s;
    };
    return (s + (i64)(strlen((i8 *)(t))));
}

byte * mlib_extractbasefile(byte * s) {
    static byte str[100];
    byte *  f;
    byte *  e;
    i64 n;
    i64 flen;
    f = mlib_extractfile(s);
    flen = (i64)(strlen((i8 *)(f)));
    if ((flen == (i64)0)) {
        return (byte*)"";
    };
    e = mlib_extractext(f,(i64)0);
    if (!!((u64)((*e)))) {
        n = ((flen - (i64)(strlen((i8 *)(e)))) - (i64)1);
        memcpy((void *)(&str),(void *)(f),(u64)(n));
        str[(n)] = (u64)0u;
        return str;
    };
    if (((u64)((*((f + flen) - (i64)1))) == '.')) {
        memcpy((void *)(&str),(void *)(f),(u64)((flen - (i64)1)));
        str[((flen - (i64)1))] = (u64)0u;
        return str;
    };
    return f;
}

byte * mlib_addext(byte * s,byte * newext) {
    byte *  sext;
    sext = mlib_extractext(s,(i64)1);
    if (((i64)((*sext)) == (i64)0)) {
        return mlib_changeext(s,newext);
    };
    return s;
}

void * mlib_alloctable(i64 n,i64 size) {
    void *  p;
    p = malloc((u64)(((n + (i64)1) * size)));
    if (!(!!(p))) {
        mlib_abortprogram((byte*)"Alloctable failure");
    };
    return p;
}

void * mlib_zalloctable(i64 n,i64 size) {
    i64 *  p;
    p = (i64 *)(mlib_alloctable(n,size));
    mlib_pcm_clearmem((void *)(p),((n + (i64)1) * size));
    return (void *)(p);
}

void mlib_checkfreelists(byte * s) {
    u64 *  p;
    u64 *  q;
    i64 aa;
    i64 i;
    L179 :;
    for (i=(i64)2;i<=(i64)2;i+=(i64)1) {
L180 :;
        p = mlib_freelist[(i)];
        L183 :;
        while (!!(p)) {
            aa = (i64)(p);
            if (((aa > (i64)4294967295) || (aa < (i64)100))) {
                msysnewc_m_print_startcon();
                msysnewc_m_print_str(s,NULL);
                msysnewc_m_print_str((byte*)"FREE LIST ERROR",NULL);
                msysnewc_m_print_i64(i,NULL);
                msysnewc_m_print_ptr(p,NULL);
                msysnewc_m_print_ptr(q,NULL);
                msysnewc_m_print_newline();
                msysnewc_m_print_end();
                ;
            };
            q = p;
            p = (u64 *)((i64)((*p)));
L184 :;
        }L185 :;
        ;
L181 :;
    }L182 :;
    ;
}

void * mlib_pcm_alloc32(void) {
    mlib_allocbytes = (i64)32;
    return mlib_pcm_alloc((i64)32);
}

void mlib_pcm_free32(void * p) {
    mlib_smallmemtotal -= (i64)32;
    if (!!((i64)0)) {
        mlib_removefrommemalloc((i32 *)(p),(i64)32);
    };
    (*(u64 *)(p)) = (u64)((i64)(mlib_freelist[((i64)2)]));
    mlib_freelist[((i64)2)] = (u64 *)(p);
}

void mlib_outbyte(void * f,i64 x) {
    fwrite((void *)(&x),(u64)((i64)1),(u64)((i64)1),f);
}

void mlib_outword16(void * f,u64 x) {
    fwrite((void *)(&x),(u64)((i64)2),(u64)((i64)1),f);
}

void mlib_outword(void * f,u64 x) {
    fwrite((void *)(&x),(u64)((i64)4),(u64)((i64)1),f);
}

void mlib_outword64(void * f,u64 x) {
    fwrite((void *)(&x),(u64)((i64)8),(u64)((i64)1),f);
}

i64 mlib_myeof(void * f) {
    i64 c;
    c = (i64)(fgetc(f));
    if ((c == (i64)-1)) {
        return (i64)1;
    };
    ungetc((i64)((i32)(c)),f);
    return (i64)0;
}

void * mlib_pcm_smallallocz(i64 n) {
    byte *  p;
    if (((mlib_alloccode = (i64)(mlib_sizeindextable[(n)])) == (i64)0)) {
        mlib_alloccode = (i64)1;
    };
    mlib_allocbytes = (i64)(mlib_allocupper[(mlib_alloccode)]);
    p = mlib_pcheapptr;
    mlib_pcheapptr += mlib_allocbytes;
    if ((mlib_pcheapptr >= mlib_pcheapend)) {
        p = (byte *)(mlib_pcm_newblock(mlib_allocbytes));
        memset((void *)(p),(i64)0,(u64)(n));
        return (void *)(p);
    };
    memset((void *)(p),(i64)0,(u64)(n));
    return (void *)(p);
}

void * mlib_pcm_smallalloc(i64 n) {
    byte *  p;
    if (((mlib_alloccode = (i64)(mlib_sizeindextable[(n)])) == (i64)0)) {
        mlib_alloccode = (i64)1;
    };
    mlib_allocbytes = (i64)(mlib_allocupper[(mlib_alloccode)]);
    p = mlib_pcheapptr;
    mlib_pcheapptr += mlib_allocbytes;
    if ((mlib_pcheapptr >= mlib_pcheapend)) {
        p = (byte *)(mlib_pcm_newblock(mlib_allocbytes));
        return (void *)(p);
    };
    return (void *)(p);
}

void mlib_strbuffer_add(struct mlib_strbuffer * dest,byte * s,i64 n) {
    i64 newlen;
    i64 oldlen;
    byte *  newptr;
    if ((n == (i64)0)) {
        msysnewc_m_print_startcon();
        msysnewc_m_print_str((byte*)"N=0",NULL);
        msysnewc_m_print_newline();
        msysnewc_m_print_end();
        ;
    };
    if ((n == (i64)-1)) {
        n = (i64)(strlen((i8 *)(s)));
    };
    oldlen = (i64)((*dest).length);
    if ((oldlen == (i64)0)) {
        (*dest).strptr = (byte *)(mlib_pcm_alloc((n + (i64)1)));
        (*dest).allocated = mlib_allocbytes;
        (*dest).length = n;
        memcpy((void *)((*dest).strptr),(void *)(s),(u64)(n));
        (*((*dest).strptr + n)) = (u64)0u;
        return;
    };
    newlen = (oldlen + n);
    if (((newlen + (i64)1) > (i64)((*dest).allocated))) {
        newptr = (byte *)(mlib_pcm_alloc((newlen + (i64)1)));
        memcpy((void *)(newptr),(void *)((*dest).strptr),(u64)(oldlen));
        (*dest).strptr = newptr;
        (*dest).allocated = mlib_allocbytes;
    };
    memcpy((void *)(((*dest).strptr + oldlen)),(void *)(s),(u64)(n));
    (*((*dest).strptr + newlen)) = (u64)0u;
    (*dest).length = newlen;
}

void mlib_gs_init(struct mlib_strbuffer * dest) {
    mlib_pcm_clearmem((void *)(dest),(i64)16);
}

void mlib_gs_free(struct mlib_strbuffer * dest) {
    if (!!((i64)((*dest).allocated))) {
        mlib_pcm_free((void *)((*dest).strptr),(i64)((*dest).allocated));
    };
}

void mlib_gs_str(struct mlib_strbuffer * dest,byte * s) {
    mlib_strbuffer_add(dest,s,(i64)-1);
}

void mlib_gs_char(struct mlib_strbuffer * dest,i64 c) {
    byte s[16];
    s[((i64)1)-1] = (u64)(c);
    s[((i64)2)-1] = (u64)0u;
    mlib_strbuffer_add(dest,s,(i64)1);
}

void mlib_gs_strn(struct mlib_strbuffer * dest,byte * s,i64 length) {
    mlib_strbuffer_add(dest,s,length);
}

void mlib_gs_strvar(struct mlib_strbuffer * dest,struct mlib_strbuffer * s) {
    mlib_strbuffer_add(dest,(*s).strptr,(i64)-1);
}

void mlib_gs_strint(struct mlib_strbuffer * dest,i64 a) {
    mlib_strbuffer_add(dest,msysnewc_strint(a,(byte *)(0)),(i64)-1);
}

void mlib_gs_strln(struct mlib_strbuffer * dest,byte * s) {
    mlib_gs_str(dest,s);
    mlib_gs_line(dest);
}

void mlib_gs_strsp(struct mlib_strbuffer * dest,byte * s) {
    mlib_gs_str(dest,s);
    mlib_gs_str(dest,(byte*)" ");
}

void mlib_gs_line(struct mlib_strbuffer * dest) {
    mlib_strbuffer_add(dest,(byte*)"\r\n",(i64)-1);
}

i64 mlib_gs_getcol(struct mlib_strbuffer * dest) {
    return (i64)((*dest).length);
}

void mlib_gs_leftstr(struct mlib_strbuffer * dest,byte * s,i64 w,i64 padch) {
    i64 col;
    i64 i;
    i64 n;
    i64 slen;
    byte str[2560];
    col = (i64)((*dest).length);
    strcpy((i8 *)(str),(i8 *)(s));
    slen = (i64)(strlen((i8 *)(s)));
    n = (w - slen);
    if ((n > (i64)0)) {
        L186 :;
        for (i=(i64)1;i<=n;i+=(i64)1) {
L187 :;
            str[((slen + i))-1] = (u64)(padch);
L188 :;
        }L189 :;
        ;
        str[(((slen + n) + (i64)1))-1] = (u64)0u;
    };
    mlib_gs_str(dest,str);
}

void mlib_gs_leftint(struct mlib_strbuffer * dest,i64 a,i64 w,i64 padch) {
    mlib_gs_leftstr(dest,msysnewc_strint(a,(byte *)(0)),w,padch);
}

void mlib_gs_padto(struct mlib_strbuffer * dest,i64 col,i64 ch) {
    i64 n;
    byte str[2560];
    i64 i;
    n = (col - (i64)((*dest).length));
    if ((n <= (i64)0)) {
        return;
    };
    L190 :;
    for (i=(i64)1;i<=n;i+=(i64)1) {
L191 :;
        str[(i)-1] = (u64)(ch);
L192 :;
    }L193 :;
    ;
    str[((n + (i64)1))-1] = (u64)0u;
    mlib_gs_str(dest,str);
}

void mlib_gs_println(struct mlib_strbuffer * dest,void * f) {
    (*((*dest).strptr + (i64)((*dest).length))) = (u64)0u;
    if ((f == 0)) {
        msysnewc_m_print_startcon();
        msysnewc_m_print_str((*dest).strptr,NULL);
        msysnewc_m_print_nogap();
        msysnewc_m_print_str((byte*)"\r",NULL);
        msysnewc_m_print_newline();
        msysnewc_m_print_end();
        ;
    } else {
        msysnewc_m_print_startfile(f);
        msysnewc_m_print_str((*dest).strptr,NULL);
        msysnewc_m_print_nogap();
        msysnewc_m_print_str((byte*)"\r",NULL);
        msysnewc_m_print_newline();
        msysnewc_m_print_end();
        ;
    };
}

i64 mlib_nextcmdparam(i64 * paramno,byte * * name,byte * * value,byte * defext) {
    static i64 infile = (i64)0;
    static byte *  filestart = 0;
    static byte *  fileptr = 0;
    static byte colonseen = (u8)0u;
    byte *  q;
    byte *  item;
    byte *  fileext;
    i64 length;
    static byte str[300];
    //reenter:
L194 :;
;
    (*value) = (byte *)(0);
    (*name) = (byte *)(0);
    if (!!(infile)) {
        if ((mlib_readnextfileitem(&fileptr,&item) == (i64)0)) {
            free((void *)(filestart));
            infile = (i64)0;
            goto L194 ;
;
        };
    } else {
        if (((*paramno) > msysnewc_nsysparams)) {
            return (i64)0;
        };
        item = msysnewc_sysparams[((*paramno))-1];
        ++(*paramno);
        length = (i64)(strlen((i8 *)(item)));
        if (((u64)((*item)) == '@')) {
            filestart = (fileptr = (byte *)(mlib_readfile((item + (i64)1))));
            if ((filestart == 0)) {
                msysnewc_m_print_startcon();
                msysnewc_m_print_str((byte*)"Can't open",NULL);
                msysnewc_m_print_str(item,NULL);
                msysnewc_m_print_newline();
                msysnewc_m_print_end();
                ;
                exit((i64)7);
            };
            infile = (i64)1;
            goto L194 ;
;
        };
        if (((u64)((*item)) == ':')) {
            colonseen = (u64)((i64)1);
            return (i64)4;
        };
    };
    (*value) = (byte *)(0);
    if (((u64)((*item)) == '-')) {
        (*name) = (item + (!!((u64)(colonseen))?(i64)0:(i64)1));
        q = (byte *)(strchr((i8 *)(item),(i64)58));
        if (!(!!(q))) {
            q = (byte *)(strchr((i8 *)(item),(i64)61));
        };
        if (!!(q)) {
            (*value) = (q + (i64)1);
            (*q) = (u64)0u;
        };
        return (!!((u64)(colonseen))?(i64)5:(i64)1);
    };
    fileext = mlib_extractext(item,(i64)0);
    (*name) = item;
    if (((i64)((*fileext)) == (i64)0)) {
        strcpy((i8 *)(str),(i8 *)((*name)));
        if ((!!(defext) && !(!!((u64)(colonseen))))) {
            (*name) = mlib_addext(str,defext);
        };
    } else if (!!(mlib_eqstring(fileext,(byte*)"dll"))) {
        return (!!((u64)(colonseen))?(i64)5:(i64)3);
    };
    return (!!((u64)(colonseen))?(i64)5:(i64)2);
}

static i64 mlib_readnextfileitem(byte * * fileptr,byte * * item) {
    byte *  p;
    byte *  pstart;
    byte *  pend;
    i64 n;
    static byte str[256];
    p = (*fileptr);
    //reenter:
L195 :;
;
    L196 :;
    while (1) {
        if (((i64)((*p))==(i64)32) || ((i64)((*p))==(i64)9) || ((i64)((*p))==(i64)13) || ((i64)((*p))==(i64)10)) {
            ++p;
        }else if (((i64)((*p))==(i64)26) || ((i64)((*p))==(i64)0)) {
            return (i64)0;
        } else {
            goto L197 ;
        };
    }L197 :;
    ;
    if (((i64)((*p))==(i64)33) || ((i64)((*p))==(i64)35)) {
        ++p;
        L198 :;
        if (((i64)((*p++))==(i64)10)) {
            goto L195 ;
;
        }else if (((i64)((*p++))==(i64)26) || ((i64)((*p++))==(i64)0)) {
            (*fileptr) = (p - (i64)1);
            return (i64)0;
        } else {
        }goto L198 ;
L199 :;
        ;
    };
    if (((i64)((*p))==(i64)34)) {
        pstart = ++p;
        L200 :;
        while (1) {
            if (((i64)((*p))==(i64)0) || ((i64)((*p))==(i64)26)) {
                msysnewc_m_print_startcon();
                msysnewc_m_print_str((byte*)"Unexpected EOF in @file",NULL);
                msysnewc_m_print_newline();
                msysnewc_m_print_end();
                ;
                exit((i64)8);
            }else if (((i64)((*p))==(i64)34)) {
                pend = p++;
                if (((u64)((*p)) == ',')) {
                    ++p;
                };
                goto L201 ;
            };
            ++p;
        }L201 :;
        ;
    } else {
        pstart = p;
        L202 :;
        while (1) {
            if (((i64)((*p))==(i64)0) || ((i64)((*p))==(i64)26)) {
                pend = p;
                goto L203 ;
            }else if (((i64)((*p))==(i64)32) || ((i64)((*p))==(i64)9) || ((i64)((*p))==(i64)44) || ((i64)((*p))==(i64)13) || ((i64)((*p))==(i64)10)) {
                pend = p++;
                goto L203 ;
            };
            ++p;
        }L203 :;
        ;
    };
    n = (pend - pstart);
    if ((n >= (i64)256)) {
        msysnewc_m_print_startcon();
        msysnewc_m_print_str((byte*)"@file item too long",NULL);
        msysnewc_m_print_newline();
        msysnewc_m_print_end();
        ;
        exit((i64)9);
    };
    memcpy((void *)(str),(void *)(pstart),(u64)(n));
    str[((n + (i64)1))-1] = (u64)0u;
    (*item) = str;
    (*fileptr) = p;
    return (i64)1;
}

void mlib_ipadstr(byte * s,i64 width,byte * padchar) {
    i64 n;
    i64 av_1;
    n = (i64)(strlen((i8 *)(s)));
    av_1 = (width - n);
    while (av_1-- > 0) {
L204 :;
        strcat((i8 *)(s),(i8 *)(padchar));
L205 :;
    }L206 :;
    ;
}

byte * mlib_padstr(byte * s,i64 width,byte * padchar) {
    static byte str[256];
    strcpy((i8 *)(str),(i8 *)(s));
    mlib_ipadstr(str,width,padchar);
    return str;
}

byte * mlib_chr(i64 c) {
    static byte str[8];
    str[((i64)1)-1] = (u64)(c);
    str[((i64)2)-1] = (u64)0u;
    return str;
}

i64 mlib_cmpstring(byte * s,byte * t) {
    i64 res;
    if (((res = (i64)(strcmp((i8 *)(s),(i8 *)(t)))) < (i64)0)) {
        return (i64)-1;
    } else if ((res > (i64)0)) {
        return (i64)1;
    } else {
        return (i64)0;
    };
}

i64 mlib_cmpstringn(byte * s,byte * t,i64 n) {
    i64 res;
    if (((res = (i64)(strncmp((i8 *)(s),(i8 *)(t),(u64)(n)))) < (i64)0)) {
        return (i64)-1;
    } else if ((res > (i64)0)) {
        return (i64)1;
    } else {
        return (i64)0;
    };
}

i64 mlib_eqstring(byte * s,byte * t) {
    return ((i64)(strcmp((i8 *)(s),(i8 *)(t))) == (i64)0);
}

i64 mlib_cmpbytes(void * p,void * q,i64 n) {
    i64 res;
    if (((res = (i64)(memcmp(p,q,(u64)(n)))) < (i64)0)) {
        return (i64)-1;
    } else if ((res > (i64)0)) {
        return (i64)1;
    } else {
        return (i64)0;
    };
}

i64 mlib_eqbytes(void * p,void * q,i64 n) {
    return ((i64)(memcmp(p,q,(u64)(n))) == (i64)0);
}

void mlib_mseed(u64 a,u64 b) {
    mlib_seed[((i64)1)-1] = (i64)(a);
    if (!!(b)) {
        mlib_seed[((i64)2)-1] = (i64)(b);
    } else {
        mlib_seed[((i64)2)-1] ^= (i64)(a);
    };
}

u64 mlib_mrandom(void) {
    u64 x;
    u64 y;
    x = (u64)(mlib_seed[((i64)1)-1]);
    y = (u64)(mlib_seed[((i64)2)-1]);
    mlib_seed[((i64)1)-1] = (i64)(y);
    x ^= (x << (i64)23);
    mlib_seed[((i64)2)-1] = (i64)((((x ^ y) ^ (x >> (i64)17)) ^ (y >> (i64)26)));
    return (u64)((mlib_seed[((i64)2)-1] + (i64)(y)));
}

i64 mlib_mrandomp(void) {
    return (i64)((mlib_mrandom() & (u64)9223372036854775807u));
}

i64 mlib_mrandomint(i64 n) {
    return (mlib_mrandomp() % n);
}

i64 mlib_mrandomrange(i64 a,i64 b) {
    i64 span;
    span = ((b - a) + (i64)1);
    if ((span <= (i64)0)) {
        return (i64)0;
    };
    return ((mlib_mrandomp() % span) + a);
}

double mlib_mrandomreal(void) {
    double x;
    L207 :;
    do {
        x = ((double)(mlib_mrandomp()) / (double)9223372036854775800.);
L208 :;
    } while (!(x != (double)1.));L209 :;
    ;
    return x;
}

double mlib_mrandomreal1(void) {
    return (double)((mlib_mrandomp() / (i64)((u64)9223372036854775807u)));
}

byte * mlib_checkpackfile(void) {
    i64 a;
    i64 offset;
    byte exefile[300];
    byte *  packexeptr;
    i64 packexesize;
    byte *  packfilename;
    i64 packfilesize;
    byte *  packfileptr;
    strcpy((i8 *)(&exefile[((i64)1)-1]),(i8 *)(oswindows_os_gethostname()));
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"Attempting to open",NULL);
    msysnewc_m_print_ptr(&exefile,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    packexeptr = mlib_readfile(&exefile[((i64)1)-1]);
    if (!(!!(packexeptr))) {
        msysnewc_m_print_startcon();
        msysnewc_m_print_str((byte*)"Can't open",NULL);
        msysnewc_m_print_ptr(&exefile,NULL);
        msysnewc_m_print_ptr(&packexeptr,NULL);
        msysnewc_m_print_newline();
        msysnewc_m_print_end();
        ;
        exit(0);
    };
    packexesize = mlib_rfsize;
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"File read OK. Size",NULL);
    msysnewc_m_print_i64(packexesize,NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
    a = (i64)((*(i32 *)((packexeptr + (packexesize - (i64)4)))));
    if ((a != (i64)1262568272)) {
        free((void *)(packexeptr));
        packfileptr = (byte *)(0);
        return (byte *)(0);
    };
    offset = (i64)((*(i32 *)((packexeptr + (packexesize - (i64)8)))));
    packfilename = (byte *)((packexeptr + offset));
    offset += ((i64)(strlen((i8 *)(packfilename))) + (i64)1);
    packfilesize = (i64)((*(i32 *)((packexeptr + offset))));
    packfileptr = ((packexeptr + offset) + (i64)4);
    return packfileptr;
}

i64 msysnewc_m_getdotindex(u64 a,i64 i) {
    return (((i64)(a) & ((i64)1 << i)) >> i);
}

void msysnewc_m_setdotindex(u64 * a,i64 i,i64 x) {
    u32 *  a32;
    if ((i >= (i64)32)) {
        (*a) = (u64)((((i64)((*a)) & ~(((i64)1 << i))) | (i64)(((u64)(x) << i))));
    } else {
        a32 = (u32 *)(a);
        (*a32) = (u64)((((i64)((u64)((*a32))) & ~(((i64)1 << i))) | (i64)(((u64)(x) << i))));
    };
}

i64 msysnewc_m_getdotslice(u64 a,i64 i,i64 j) {
    if ((i >= j)) {
        return (i64)(((a >> j) & ~(((u64)18446744073709551615u << ((i - j) + (i64)1)))));
    } else {
        return (i64)(((a >> i) & ~(((u64)18446744073709551615u << ((j - i) + (i64)1)))));
    };
}

void msysnewc_m_setdotslice(u64 * a,i64 i,i64 j,u64 x) {
    u64 mask64;
    u64 mask;
    u32 *  a32;
    if ((i > j)) {
        msysnewc_m_print_startcon();
        msysnewc_m_print_str((byte*)"SETDOTSLICE?",NULL);
        msysnewc_m_print_newline();
        msysnewc_m_print_end();
        ;
        exit((i64)52);
    };
    if ((j >= (i64)32)) {
        mask64 = (~(((u64)18446744073709551615u << ((j - i) + (i64)1))) << i);
        (*a) = (((*a) & ~(mask64)) | (x << i));
    } else {
        a32 = (u32 *)(a);
        mask = (~(((u64)18446744073709551615u << ((j - i) + (i64)1))) << i);
        (*a32) = (((u64)((*a32)) & ~(mask)) | (x << i));
    };
}

i64 msysnewc_m_get_nprocs(void) {
    return msysnewc__fnnprocs;
}

i64 msysnewc_m_get_nexports(void) {
    return msysnewc__fnnexports;
}

void * msysnewc_m_get_procname(i64 n) {
    return (void *)(msysnewc__fnnames[(n)-1]);
}

byte * msysnewc_m_get_procaddr(i64 n) {
    return (byte *)(msysnewc__fnaddresses[(n)-1]);
}

void * msysnewc_m_get_procexport(i64 n) {
    return (void *)(&msysnewc__fnexports[(n)-1]);
}

static void msysnewc_pushio(void) {
    if ((msysnewc_niostack >= (i64)10)) {
        printf((i8 *)((byte*)"Too many io levels\n"));
        exit((i64)53);
    };
    ++msysnewc_niostack;
    msysnewc_outchan_stack[(msysnewc_niostack)-1] = msysnewc_outchan;
    msysnewc_outdev_stack[(msysnewc_niostack)-1] = msysnewc_outdev;
    msysnewc_fmtstr_stack[(msysnewc_niostack)-1] = msysnewc_fmtstr;
    msysnewc_needgap_stack[(msysnewc_niostack)-1] = (u64)(msysnewc_needgap);
    msysnewc_needgap = (i64)0;
    msysnewc_fmtstr = (byte *)(0);
    msysnewc_outchan = 0;
}

void msysnewc_m_print_startfile(void * dev) {
    msysnewc_pushio();
    msysnewc_outchan = dev;
    if (!!(dev)) {
        msysnewc_outdev = (i64)2;
    } else {
        msysnewc_outdev = (i64)1;
    };
}

void msysnewc_m_print_startstr(byte * s) {
    byte * *  p;
    msysnewc_pushio();
    msysnewc_ptr_stack[(msysnewc_niostack)-1] = s;
    p = &msysnewc_ptr_stack[(msysnewc_niostack)-1];
    msysnewc_outchan = (void *)(p);
    msysnewc_outdev = (i64)3;
}

void msysnewc_m_print_startptr(byte * * p) {
    msysnewc_pushio();
    msysnewc_outchan = (void *)(p);
    msysnewc_outdev = (i64)3;
}

void msysnewc_m_print_startcon(void) {
    msysnewc_pushio();
    msysnewc_outdev = (i64)1;
}

void msysnewc_m_print_setfmt(byte * format) {
    msysnewc_fmtstr = format;
}

void msysnewc_m_print_end(void) {
    msysnewc_needgap = (i64)0;
    msysnewc_nextfmtchars((i64)1);
    if ((msysnewc_niostack == (i64)0)) {
        return;
    };
    msysnewc_outchan = msysnewc_outchan_stack[(msysnewc_niostack)-1];
    msysnewc_outdev = msysnewc_outdev_stack[(msysnewc_niostack)-1];
    msysnewc_fmtstr = msysnewc_fmtstr_stack[(msysnewc_niostack)-1];
    msysnewc_needgap = (i64)(msysnewc_needgap_stack[(msysnewc_niostack)-1]);
    --msysnewc_niostack;
}

void msysnewc_m_print_ptr(void * a,byte * fmtstyle) {
    msysnewc_nextfmtchars((i64)0);
    msysnewc_printstr(msysnewc_strword((u64)(a),(byte*)"z8h"));
    msysnewc_needgap = (i64)1;
}

void msysnewc_m_print_i64(i64 a,byte * fmtstyle) {
    byte s[40];
    struct msysnewc_fmtrec fmt;
    i64 n;
    msysnewc_nextfmtchars((i64)0);
    if ((fmtstyle == 0)) {
        if ((a >= (i64)0)) {
            n = msysnewc_u64tostr((u64)(a),s,(u64)((i64)10),(i64)0);
        } else {
            s[((i64)1)-1] = '-';
            n = (msysnewc_u64tostr((u64)(-(a)),&s[((i64)2)-1],(u64)((i64)10),(i64)0) + (i64)1);
        };
        msysnewc_printstr_n(s,n);
    } else {
        msysnewc_strtofmt(fmtstyle,(i64)-1,&fmt);
        if (((u64)(fmt.param) == 'V')) {
            msysnewc_fmtparam = a;
            msysnewc_needgap = (i64)0;
        } else {
            msysnewc_tostr_i64(a,&fmt);
        };
    };
    msysnewc_needgap = (i64)1;
}

void msysnewc_m_print_u64(u64 a,byte * fmtstyle) {
    struct msysnewc_fmtrec fmt;
    msysnewc_nextfmtchars((i64)0);
    if ((fmtstyle == 0)) {
        msysnewc_printstr(msysnewc_strword(a,(byte *)(0)));
    } else {
        msysnewc_strtofmt(fmtstyle,(i64)-1,&fmt);
        msysnewc_tostr_u64(a,&fmt);
    };
    msysnewc_needgap = (i64)1;
}

void msysnewc_m_print_r64(double x,byte * fmtstyle) {
    byte s[360];
    struct msysnewc_fmtrec fmt;
    msysnewc_nextfmtchars((i64)0);
    if ((fmtstyle == 0)) {
        sprintf((i8 *)(s),(i8 *)((byte*)"%f"),x);
        msysnewc_printstr(s);
    } else {
        msysnewc_strtofmt(fmtstyle,(i64)-1,&fmt);
        msysnewc_tostr_r64(x,&fmt);
    };
    msysnewc_needgap = (i64)1;
}

void msysnewc_m_print_r32(float x,byte * fmtstyle) {
    msysnewc_m_print_r64((double)(x),fmtstyle);
}

void msysnewc_m_print_c8(i64 a,byte * fmtstyle) {
    byte s[40];
    msysnewc_nextfmtchars((i64)0);
    s[((i64)1)-1] = (u64)(a);
    s[((i64)2)-1] = (u64)0u;
    msysnewc_printstr(s);
    msysnewc_needgap = (i64)1;
}

void msysnewc_m_print_str(byte * s,byte * fmtstyle) {
    struct msysnewc_fmtrec fmt;
    msysnewc_nextfmtchars((i64)0);
    if ((fmtstyle == 0)) {
        msysnewc_printstr(s);
    } else {
        msysnewc_strtofmt(fmtstyle,(i64)-1,&fmt);
        msysnewc_tostr_str(s,&fmt);
    };
    msysnewc_needgap = (i64)1;
}

void msysnewc_m_print_newline(void) {
    msysnewc_needgap = (i64)0;
    msysnewc_nextfmtchars((i64)1);
    msysnewc_printstr((byte*)"\r\n");
}

void msysnewc_m_print_nogap(void) {
    msysnewc_needgap = (i64)0;
}

void msysnewc_printstr(byte * s) {
    byte * *  p;
    if ((msysnewc_outdev==(i64)1)) {
        printf((i8 *)((byte*)"%s"),s);
    }else if ((msysnewc_outdev==(i64)2)) {
        fprintf(msysnewc_outchan,(i8 *)((byte*)"%s"),s);
    }else if ((msysnewc_outdev==(i64)3)) {
        p = (byte * *)(msysnewc_outchan);
        strcpy((i8 *)((*p)),(i8 *)(s));
        (*p) += (i64)(strlen((i8 *)(s)));
    };
}

void msysnewc_printstr_n(byte * s,i64 n) {
    byte str[256];
    byte * *  p;
    if ((n==(i64)-1)) {
        n = (i64)(strlen((i8 *)(s)));
    }else if ((n==(i64)0)) {
        return;
    };
    if ((msysnewc_outdev==(i64)3)) {
        p = (byte * *)(msysnewc_outchan);
        memcpy((void *)((*p)),(void *)(s),(u64)(n));
        (*p) += n;
        (*(*p)) = (u64)0u;
    }else if ((msysnewc_outdev==(i64)2)) {
        s = msysnewc_makezstring(s,n,str);
        fprintf(msysnewc_outchan,(i8 *)((byte*)"%s"),s);
        msysnewc_freezstring(s,n);
    }else if ((msysnewc_outdev==(i64)1)) {
        s = msysnewc_makezstring(s,n,str);
        printf((i8 *)((byte*)"%s"),s);
        msysnewc_freezstring(s,n);
    };
}

void msysnewc_printstrn_app(byte * s,i64 length,void * f) {
    if (!!(length)) {
        if ((f == 0)) {
            printf("%.*s",(i32)length,s);;
        } else {
            fprintf(f,"%.*s",(i32)length,s);;
        };
    };
}

static byte * msysnewc_makezstring(byte * s,i64 n,byte * local) {
    byte *  t;
    if ((n < (i64)256)) {
        memcpy((void *)(local),(void *)(s),(u64)(n));
        (*(local + n)) = (u64)0u;
        return local;
    } else {
        t = (byte *)(mlib_pcm_alloc((n + (i64)1)));
        memcpy((void *)(t),(void *)(s),(u64)(n));
        (*(t + n)) = (u64)0u;
        return t;
    };
}

static void msysnewc_freezstring(byte * t,i64 n) {
    if ((n >= (i64)256)) {
        mlib_pcm_free((void *)(t),(n + (i64)1));
    };
}

static void msysnewc_printchar(i64 ch) {
    byte * *  p;
    if ((msysnewc_outdev==(i64)1)) {
        printf("%c",(int)ch);
    }else if ((msysnewc_outdev==(i64)2)) {
        fprintf(msysnewc_outchan,"%c",(int)ch);
    }else if ((msysnewc_outdev==(i64)3)) {
        p = (byte * *)(msysnewc_outchan);
        (*(*p)) = (u64)(ch);
        (*p) += (i64)1;
        (*(*p)) = (u64)0u;
    };
}

void msysnewc_nextfmtchars(i64 lastx) {
    byte c;
    byte *  pstart;
    i64 n;
    if (!(!!(msysnewc_fmtstr))) {
        if (!!(msysnewc_needgap)) {
            msysnewc_printchar((i64)32);
        };
        msysnewc_needgap = (i64)0;
        return;
    };
    pstart = msysnewc_fmtstr;
    n = (i64)0;
    L210 :;
    while (!!((i64)1)) {
        c = (u64)((*msysnewc_fmtstr));
        switch ((i64)(c)) {
        case 35:;
        {
            if (!!(lastx)) {
                goto L213 ;
;
            };
            ++msysnewc_fmtstr;
            if (!!(n)) {
                msysnewc_printstr_n(pstart,n);
            };
            return;
        }break;
        case 0:;
        {
            if (!!(n)) {
                msysnewc_printstr_n(pstart,n);
            } else if (!(!!(lastx))) {
                msysnewc_printstr_n((byte*)"|",(i64)1);
            };
            return;
        }break;
        case 126:;
        {
            if (!!(n)) {
                msysnewc_printstr_n(pstart,n);
                n = (i64)0;
            };
            ++msysnewc_fmtstr;
            c = (u64)((*msysnewc_fmtstr));
            if (!!((u64)(c))) {
                ++msysnewc_fmtstr;
                msysnewc_printchar((i64)(c));
            };
            pstart = msysnewc_fmtstr;
        }break;
        default: {
            //skip:
L213 :;
;
            ++n;
            ++msysnewc_fmtstr;
        }
        } //SW
;
L211 :;
    }L212 :;
    ;
}

void msysnewc_strtofmt(byte * s,i64 slen,struct msysnewc_fmtrec * fmt) {
    byte c;
    byte wset;
    i64 n;
    byte str[100];
    (*fmt) = msysnewc_defaultfmt;
    if ((s == 0)) {
        return;
    };
    if ((slen == (i64)-1)) {
        slen = (i64)(strlen((i8 *)(s)));
    };
    memcpy((void *)(str),(void *)(s),(u64)(slen));
    str[(slen)] = (u64)0u;
    s = str;
    wset = (u64)((i64)0);
    L214 :;
    while (!!((u64)((*s)))) {
        c = (u64)((*s));
        ++s;
        switch ((i64)(c)) {
        case 66:;
        case 98:;
        {
            (*fmt).base = (u64)((i64)2);
        }break;
        case 72:;
        case 104:;
        {
            (*fmt).base = (u64)((i64)16);
        }break;
        case 79:;
        case 111:;
        {
            (*fmt).base = (u64)((i64)8);
        }break;
        case 88:;
        case 120:;
        {
            c = (u64)((*s));
            if (!!((u64)(c))) {
                switch ((i64)(c)) {
                case 48:;
                case 49:;
                case 50:;
                case 51:;
                case 52:;
                case 53:;
                case 54:;
                case 55:;
                case 56:;
                case 57:;
                {
                    c = ((u64)(c) - '0');
                }break;
                case 65:;
                case 66:;
                case 67:;
                case 68:;
                case 69:;
                case 70:;
                {
                    c = (u64)((((u64)(c) - 'A') + (i64)10));
                }break;
                case 97:;
                case 98:;
                case 99:;
                case 100:;
                case 101:;
                case 102:;
                {
                    c = (u64)((((u64)(c) - 'a') + (i64)10));
                }break;
                default: {
                    c = (u64)10u;
                }
                } //SW
;
                (*fmt).base = (u64)(c);
                ++s;
            };
        }break;
        case 81:;
        case 113:;
        {
            (*fmt).quotechar = '"';
        }break;
        case 126:;
        {
            (*fmt).quotechar = '~';
        }break;
        case 74:;
        case 106:;
        {
            (*fmt).justify = (u64)(toupper((i64)((i32)((*s)))));
            if (!!((u64)((*s)))) {
                ++s;
            };
        }break;
        case 65:;
        {
            (*fmt).lettercase = 'A';
        }break;
        case 97:;
        {
            (*fmt).lettercase = 'a';
        }break;
        case 90:;
        case 122:;
        {
            (*fmt).padchar = '0';
        }break;
        case 83:;
        case 115:;
        {
            (*fmt).sepchar = (u64)((*s));
            if (!!((u64)((*s)))) {
                ++s;
            };
        }break;
        case 80:;
        case 112:;
        {
            (*fmt).padchar = (u64)((*s));
            if (!!((u64)((*s)))) {
                ++s;
            };
        }break;
        case 84:;
        case 116:;
        {
            (*fmt).suffix = (u64)((*s));
            if (!!((u64)((*s)))) {
                ++s;
            };
        }break;
        case 87:;
        case 119:;
        {
            (*fmt).usigned = 'W';
        }break;
        case 69:;
        case 101:;
        {
            (*fmt).realfmt = 'e';
        }break;
        case 70:;
        case 102:;
        {
            (*fmt).realfmt = 'f';
        }break;
        case 71:;
        case 103:;
        {
            (*fmt).realfmt = 'g';
        }break;
        case 46:;
        {
            wset = (u64)((i64)1);
        }break;
        case 44:;
        case 95:;
        {
            (*fmt).sepchar = (u64)(c);
        }break;
        case 43:;
        {
            (*fmt).plus = '+';
        }break;
        case 68:;
        case 100:;
        {
            (*fmt).charmode = 'D';
        }break;
        case 67:;
        case 99:;
        {
            (*fmt).charmode = 'C';
        }break;
        case 77:;
        case 109:;
        {
            (*fmt).heapmode = 'M';
        }break;
        case 86:;
        case 118:;
        {
            (*fmt).param = 'V';
        }break;
        case 42:;
        {
            n = msysnewc_fmtparam;
            goto L217 ;
;
        }break;
        default: {
            if ((((u64)(c) >= '0') && ((u64)(c) <= '9'))) {
                n = ((u64)(c) - '0');
                L218 :;
                while (1) {
                    c = (u64)((*s));
                    if (((i64)((*s)) == (i64)0)) {
                        goto L219 ;
                    };
                    if ((((u64)(c) >= '0') && ((u64)(c) <= '9'))) {
                        ++s;
                        n = (((n * (i64)10) + (i64)(c)) - (i64)48);
                    } else {
                        goto L219 ;
                    };
                }L219 :;
                ;
                //gotwidth:
L217 :;
;
                if (!(!!((u64)(wset)))) {
                    (*fmt).minwidth = (u64)(n);
                    wset = (u64)((i64)1);
                } else {
                    (*fmt).precision = n;
                };
            };
        }
        } //SW
;
L215 :;
    }L216 :;
    ;
}

static i64 msysnewc_domultichar(byte * p,i64 n,byte * dest,struct msysnewc_fmtrec * fmt) {
    byte str[20];
    byte *  q;
    i64 nchars;
    i64 av_1;
    q = str;
    nchars = n;
    av_1 = n;
    while (av_1-- > 0) {
L220 :;
        if (((i64)((*p)) == (i64)0)) {
            goto L222 ;
        };
        (*q) = (u64)((*p));
        ++q;
        ++p;
L221 :;
    }L222 :;
    ;
    (*q) = (u64)0u;
    return msysnewc_expandstr(str,dest,(i64)(strlen((i8 *)(str))),fmt);
}

static i64 msysnewc_expandstr(byte * s,byte * t,i64 n,struct msysnewc_fmtrec * fmt) {
    i64 i;
    i64 w;
    i64 m;
    i64 av_1;
    i64 av_2;
    i64 av_3;
    i64 av_4;
    i64 av_5;
    w = (i64)((*fmt).minwidth);
    if (((w == (i64)0) || (w <= n))) {
        strncpy((i8 *)(t),(i8 *)(s),(u64)(n));
        (*(t + n)) = (u64)0u;
        return n;
    };
    if (((u64)((*fmt).justify) == 'L')) {
        strncpy((i8 *)(t),(i8 *)(s),(u64)(n));
        t += n;
        L223 :;
        for (i=(i64)1;i<=(w - n);i+=(i64)1) {
L224 :;
            (*t) = (u64)((*fmt).padchar);
            ++t;
L225 :;
        }L226 :;
        ;
        (*t) = (u64)0u;
    } else if (((u64)((*fmt).justify) == 'R')) {
        if (((((u64)((*fmt).padchar) == '0') && !!((u64)((*fmt).base))) && (((u64)((*s)) == '-') || ((u64)((*s)) == '+')))) {
            (*t) = (u64)((*s));
            ++t;
            av_2 = (w - n);
            while (av_2-- > 0) {
L227 :;
                (*t) = (u64)((*fmt).padchar);
                ++t;
L228 :;
            }L229 :;
            ;
            strncpy((i8 *)(t),(i8 *)((s + (i64)1)),(u64)((n - (i64)1)));
            (*((t + n) - (i64)1)) = (u64)0u;
        } else {
            av_3 = (w - n);
            while (av_3-- > 0) {
L230 :;
                (*t) = (u64)((*fmt).padchar);
                ++t;
L231 :;
            }L232 :;
            ;
            strncpy((i8 *)(t),(i8 *)(s),(u64)(n));
            (*(t + n)) = (u64)0u;
        };
    } else {
        m = (((w - n) + (i64)1) / (i64)2);
        av_4 = m;
        while (av_4-- > 0) {
L233 :;
            (*t) = (u64)((*fmt).padchar);
            ++t;
L234 :;
        }L235 :;
        ;
        strncpy((i8 *)(t),(i8 *)(s),(u64)(n));
        t += n;
        av_5 = ((w - n) - m);
        while (av_5-- > 0) {
L236 :;
            (*t) = (u64)((*fmt).padchar);
            ++t;
L237 :;
        }L238 :;
        ;
        (*t) = (u64)0u;
    };
    return w;
}

static u64 msysnewc_xdivrem(u64 a,u64 b,u64 * remainder) {
    u64 q;
    mlib_abortprogram((byte*)"XDIVREM");
    return q;
}

static i64 msysnewc_u64tostr(u64 aa,byte * s,u64 base,i64 sep) {
    byte t[360];
    i64 i;
    i64 j;
    i64 k;
    i64 g;
    byte *  s0;
    i = (i64)0;
    k = (i64)0;
    g = (((i64)(base) == (i64)10)?(i64)3:(i64)4);
    L239 :;
    do {
        t[(++i)] = (u64)(msysnewc_digits[((i64)((aa % base)))]);
        aa = (aa / base);
        ++k;
        if (((!!(sep) && ((i64)(aa) != (i64)0)) && (k == g))) {
            t[(++i)] = (u64)(sep);
            k = (i64)0;
        };
L240 :;
    } while (!((i64)(aa) == (i64)0));L241 :;
    ;
    j = i;
    s0 = s;
    L242 :;
    while (!!(i)) {
        (*s) = (u64)(t[(i--)]);
        ++s;
L243 :;
    }L244 :;
    ;
    (*s) = (u64)0u;
    return j;
}

static i64 msysnewc_i64tostrfmt(i64 aa,byte * s,struct msysnewc_fmtrec * fmt) {
    byte str[360];
    i64 n;
    i64 usigned;
    static u64 mindint = (u64)9223372036854775808u;
    usigned = (i64)0;
    if (!!((u64)((*fmt).usigned))) {
        usigned = (i64)1;
    };
    if (((aa == (i64)(mindint)) && !(!!(usigned)))) {
        str[((i64)0)] = '-';
        n = (msysnewc_i64mintostr(&str[((i64)1)],(i64)((*fmt).base),(i64)((*fmt).sepchar)) + (i64)1);
    } else {
        if (((!(!!(usigned)) && (aa < (i64)0)) || !!((u64)((*fmt).plus)))) {
            if ((aa < (i64)0)) {
                aa = -(aa);
                str[((i64)0)] = '-';
            } else {
                str[((i64)0)] = '+';
            };
            n = (msysnewc_u64tostr((u64)(aa),&str[((i64)1)],(u64)((*fmt).base),(i64)((*fmt).sepchar)) + (i64)1);
        } else {
            n = msysnewc_u64tostr((u64)(aa),str,(u64)((*fmt).base),(i64)((*fmt).sepchar));
        };
    };
    if (!!((u64)((*fmt).suffix))) {
        str[(n)] = (u64)((*fmt).suffix);
        str[(++n)] = (u64)0u;
    };
    if (((((i64)((u64)((*fmt).base)) > (i64)10) || !!((u64)((*fmt).suffix))) && ((u64)((*fmt).lettercase) == 'a'))) {
        msysnewc_convlcstring(str);
    };
    return msysnewc_expandstr(str,s,n,fmt);
}

static i64 msysnewc_u64tostrfmt(i64 aa,byte * s,struct msysnewc_fmtrec * fmt) {
    byte str[360];
    i64 n;
    n = msysnewc_u64tostr((u64)(aa),str,(u64)((*fmt).base),(i64)((*fmt).sepchar));
    if (!!((u64)((*fmt).suffix))) {
        str[(n)] = (u64)((*fmt).suffix);
        str[(++n)] = (u64)0u;
    };
    if ((((i64)((u64)((*fmt).base)) > (i64)10) || (!!((u64)((*fmt).suffix)) && ((u64)((*fmt).lettercase) == 'a')))) {
        msysnewc_convlcstring(str);
    };
    return msysnewc_expandstr(str,s,n,fmt);
}

static i64 msysnewc_i64mintostr(byte * s,i64 base,i64 sep) {
    byte t[360];
    i64 i;
    i64 j;
    i64 k;
    i64 g;
    switch (base) {
    case 10:;
    {
        strcpy((i8 *)(&t[((i64)0)]),(i8 *)((byte*)"9223372036854775808"));
        j = (i64)3;
    }break;
    case 16:;
    {
        strcpy((i8 *)(&t[((i64)0)]),(i8 *)((byte*)"8000000000000000"));
        j = (i64)1;
    }break;
    case 2:;
    {
        strcpy((i8 *)(&t[((i64)0)]),(i8 *)((byte*)"1000000000000000000000000000000000000000000000000000000000000000"));
        j = (i64)7;
    }break;
    default: {
        strcpy((i8 *)(&t[((i64)0)]),(i8 *)((byte*)"<mindint>"));
    }
    } //SW
;
    i = (i64)(strlen((i8 *)(&t[((i64)0)])));
    s += i;
    if (!!(sep)) {
        s += j;
    };
    (*s) = (u64)0u;
    k = (i64)0;
    g = ((base == (i64)10)?(i64)3:(i64)4);
    L245 :;
    while (!!(i)) {
        --s;
        (*s) = (u64)(t[((i-- - (i64)1))]);
        if (((!!(sep) && !!(i)) && (++k == g))) {
            --s;
            (*s) = (u64)(sep);
            k = (i64)0;
        };
L246 :;
    }L247 :;
    ;
    return (i64)(strlen((i8 *)(s)));
}

static i64 msysnewc_strtostrfmt(byte * s,byte * t,i64 n,struct msysnewc_fmtrec * fmt) {
    byte *  u;
    byte *  v;
    byte str[256];
    i64 w;
    i64 nheap;
    nheap = (i64)0;
    if ((!!((u64)((*fmt).quotechar)) || !!((u64)((*fmt).lettercase)))) {
        if ((n < (i64)256)) {
            u = str;
        } else {
            nheap = (n + (i64)3);
            u = (byte *)(mlib_pcm_alloc(nheap));
        };
        if (!!((u64)((*fmt).quotechar))) {
            v = u;
            (*v) = (u64)((*fmt).quotechar);
            ++v;
            if (!!(n)) {
                strcpy((i8 *)(v),(i8 *)(s));
                v += n;
            };
            (*v) = (u64)((*fmt).quotechar);
            ++v;
            (*v) = (u64)0u;
            n += (i64)2;
        } else {
            memcpy((void *)(u),(void *)(s),(u64)(n));
        };
        switch ((i64)((*fmt).lettercase)) {
        case 97:;
        {
            msysnewc_convlcstring(u);
        }break;
        case 65:;
        {
            msysnewc_convucstring(u);
        }break;
        default: {
        }
        } //SW
;
        s = u;
    };
    w = (i64)((*fmt).minwidth);
    if ((w > n)) {
        n = msysnewc_expandstr(s,t,n,fmt);
    } else {
        memcpy((void *)(t),(void *)(s),(u64)(n));
    };
    if (!!(nheap)) {
        mlib_pcm_free((void *)(u),nheap);
    };
    return n;
}

static void msysnewc_tostr_i64(i64 a,struct msysnewc_fmtrec * fmt) {
    byte str[360];
    i64 n;
    if (((i64)((*fmt).charmode)==(i64)0)) {
        n = msysnewc_i64tostrfmt(a,str,fmt);
    }else if (((i64)((*fmt).charmode)==(i64)68) || ((i64)((*fmt).charmode)==(i64)100)) {
        n = msysnewc_domultichar((byte *)(&a),(i64)8,str,fmt);
    } else {
        msysnewc_printchar(a);
        return;
    };
    msysnewc_printstr_n(str,n);
}

static void msysnewc_tostr_u64(u64 a,struct msysnewc_fmtrec * fmt) {
    byte str[360];
    i64 n;
    if (((i64)((*fmt).charmode)==(i64)68) || ((i64)((*fmt).charmode)==(i64)100)) {
        n = msysnewc_domultichar((byte *)(&a),(i64)8,str,fmt);
    }else if (((i64)((*fmt).charmode)==(i64)67) || ((i64)((*fmt).charmode)==(i64)99)) {
        msysnewc_printchar((i64)(a));
        return;
    } else {
        n = msysnewc_u64tostrfmt((i64)(a),str,fmt);
    };
    msysnewc_printstr_n(str,n);
}

static void msysnewc_tostr_r64(double x,struct msysnewc_fmtrec * fmt) {
    byte str[360];
    byte str2[360];
    byte cfmt[10];
    i64 n;
    cfmt[((i64)0)] = '%';
    if (!!((i64)((*fmt).precision))) {
        cfmt[((i64)1)] = '.';
        cfmt[((i64)2)] = '*';
        cfmt[((i64)3)] = (u64)((*fmt).realfmt);
        cfmt[((i64)4)] = (u64)0u;
        sprintf((i8 *)(str),(i8 *)(cfmt),(i64)((*fmt).precision),x);
    } else {
        cfmt[((i64)1)] = (u64)((*fmt).realfmt);
        cfmt[((i64)2)] = (u64)0u;
        sprintf((i8 *)(str),(i8 *)(cfmt),x);
    };
    n = (i64)(strlen((i8 *)(str)));
    if ((n < (i64)((u64)((*fmt).minwidth)))) {
        n = msysnewc_expandstr(str,str2,n,fmt);
        strcpy((i8 *)(str),(i8 *)(str2));
    };
    msysnewc_printstr_n(str,n);
}

static void msysnewc_tostr_str(byte * s,struct msysnewc_fmtrec * fmt) {
    i64 oldlen;
    i64 newlen;
    i64 n;
    byte *  t;
    oldlen = (i64)(strlen((i8 *)(s)));
    newlen = oldlen;
    if (((!!((u64)((*fmt).quotechar)) || ((i64)((u64)((*fmt).minwidth)) > newlen)) || !!((u64)((*fmt).lettercase)))) {
        if (!!((u64)((*fmt).quotechar))) {
            newlen += (i64)2;
        };
        if (((i64)((u64)((*fmt).minwidth)) > newlen)) {
            newlen = (i64)((*fmt).minwidth);
        };
        t = (byte *)(mlib_pcm_alloc((newlen + (i64)1)));
        n = msysnewc_strtostrfmt(s,t,oldlen,fmt);
        msysnewc_printstr_n(t,n);
        mlib_pcm_free((void *)(t),(newlen + (i64)1));
    } else {
        msysnewc_printstr_n(s,oldlen);
    };
}

static struct msysnewc_fmtrec * msysnewc_getfmt(byte * fmtstyle) {
    static struct msysnewc_fmtrec fmt;
    if (!!(fmtstyle)) {
        msysnewc_strtofmt(fmtstyle,(i64)-1,&fmt);
        return &fmt;
    } else {
        return &msysnewc_defaultfmt;
    };
}

byte * msysnewc_strint(i64 a,byte * fmtstyle) {
    static byte str[100];
    struct msysnewc_fmtrec *  fmt;
    msysnewc_m_print_startstr(str);
    msysnewc_tostr_i64(a,(fmt = msysnewc_getfmt(fmtstyle)));
    msysnewc_m_print_end();
    return msysnewc_getstr(str,fmt);
}

void msysnewc_getstrint(i64 a,byte * dest) {
    msysnewc_m_print_startstr(dest);
    msysnewc_tostr_i64(a,msysnewc_getfmt((byte *)(0)));
    msysnewc_m_print_end();
}

byte * msysnewc_strword(u64 a,byte * fmtstyle) {
    static byte str[100];
    struct msysnewc_fmtrec *  fmt;
    msysnewc_m_print_startstr(str);
    msysnewc_tostr_u64(a,(fmt = msysnewc_getfmt(fmtstyle)));
    msysnewc_m_print_end();
    return msysnewc_getstr(str,fmt);
}

byte * msysnewc_strreal(double a,byte * fmtstyle) {
    static byte str[320];
    struct msysnewc_fmtrec *  fmt;
    msysnewc_m_print_startstr(str);
    msysnewc_tostr_r64(a,(fmt = msysnewc_getfmt(fmtstyle)));
    msysnewc_m_print_end();
    return msysnewc_getstr(str,fmt);
}

static byte * msysnewc_getstr(byte * s,struct msysnewc_fmtrec * fmt) {
    if (!!((u64)((*fmt).heapmode))) {
        return mlib_pcm_copyheapstring(s);
    } else {
        return s;
    };
}

static void msysnewc_initreadbuffer(void) {
    if (!!(msysnewc_rd_buffer)) {
        return;
    };
    msysnewc_rd_buffer = (byte *)(mlib_pcm_alloc((i64)16384));
    (*msysnewc_rd_buffer) = (u64)0u;
    msysnewc_rd_pos = (msysnewc_rd_lastpos = msysnewc_rd_buffer);
}

void msysnewc_m_read_conline(void) {
    msysnewc_initreadbuffer();
    mlib_readlinen(0,msysnewc_rd_buffer,(i64)16384);
    msysnewc_rd_length = (i64)(strlen((i8 *)(msysnewc_rd_buffer)));
    msysnewc_rd_pos = msysnewc_rd_buffer;
    msysnewc_rd_lastpos = (byte *)(0);
}

void msysnewc_m_read_fileline(void * f) {
    msysnewc_initreadbuffer();
    mlib_readlinen(f,msysnewc_rd_buffer,(i64)16384);
    msysnewc_rd_length = (i64)(strlen((i8 *)(msysnewc_rd_buffer)));
    msysnewc_rd_pos = msysnewc_rd_buffer;
    msysnewc_rd_lastpos = (byte *)(0);
}

void msysnewc_m_read_strline(byte * s) {
    i64 n;
    msysnewc_initreadbuffer();
    n = (i64)(strlen((i8 *)(s)));
    if ((n < (i64)16384)) {
        strcpy((i8 *)(msysnewc_rd_buffer),(i8 *)(s));
    } else {
        memcpy((void *)(msysnewc_rd_buffer),(void *)(s),(u64)((i64)16383));
        (*((msysnewc_rd_buffer + (i64)16384) - (i64)1)) = (u64)0u;
    };
    msysnewc_rd_length = n;
    msysnewc_rd_pos = msysnewc_rd_buffer;
    msysnewc_rd_lastpos = (byte *)(0);
}

static byte * msysnewc_readitem(i64 * itemlength) {
    byte *  p;
    byte *  s;
    byte *  itemstr;
    byte quotechar;
    byte c;
    if (!(!!(msysnewc_rd_buffer))) {
        msysnewc_initreadbuffer();
    };
    s = msysnewc_rd_pos;
    L248 :;
    while ((((u64)((*s)) == ' ') || ((i64)((*s)) == (i64)9))) {
        ++s;
L249 :;
    }L250 :;
    ;
    itemstr = s;
    msysnewc_rd_lastpos = (msysnewc_rd_pos = s);
    if (((i64)((*s)) == (i64)0)) {
        msysnewc_termchar = (i64)0;
        (*itemlength) = (i64)0;
        return s;
    };
    quotechar = (u64)0u;
    if (((u64)((*s)) == '"')) {
        quotechar = '"';
        ++s;
    } else if (((u64)((*s)) == (u64)39u)) {
        quotechar = (u64)39u;
        ++s;
    };
    p = (itemstr = s);
    L251 :;
    while (!!((u64)((*s)))) {
        c = (u64)((*s++));
        switch ((i64)(c)) {
        case 32:;
        case 9:;
        case 44:;
        case 61:;
        {
            if ((!!((u64)(quotechar)) || (p == s))) {
                goto L254 ;
;
            };
            msysnewc_termchar = (i64)(c);
            goto L253 ;
        }break;
        default: {
            //normalchar:
L254 :;
;
            if (((u64)(c) == (u64)(quotechar))) {
                if (((u64)((*s)) == (u64)(quotechar))) {
                    (*p) = (u64)(c);
                    ++s;
                    ++p;
                } else {
                    msysnewc_termchar = (i64)((*s));
                    if (((msysnewc_termchar == (i64)44) || (msysnewc_termchar == (i64)61))) {
                        ++s;
                        msysnewc_termchar = (i64)((*s));
                    };
                    goto L253 ;
                };
            } else {
                (*p) = (u64)(c);
                ++p;
            };
        }
        } //SW
;
L252 :;
    }L253 :;
    ;
    if (((i64)((*s)) == (i64)0)) {
        msysnewc_termchar = (i64)0;
    };
    (*itemlength) = (p - itemstr);
    msysnewc_rd_pos = s;
    return itemstr;
}

i64 msysnewc_strtoint(byte * s,i64 length,i64 base) {
    byte signd;
    u64 aa;
    byte c;
    byte d;
    msysnewc_itemerror = (i64)0;
    if ((length == (i64)-1)) {
        length = (i64)(strlen((i8 *)(s)));
    };
    signd = (u64)((i64)0);
    if ((!!(length) && ((u64)((*s)) == '-'))) {
        signd = (u64)((i64)1);
        ++s;
        --length;
    } else if ((!!(length) && ((u64)((*s)) == '+'))) {
        ++s;
        --length;
    };
    aa = (u64)((i64)0);
    L255 :;
    while (!!(length)) {
        c = (u64)((*s++));
        --length;
        switch ((i64)(c)) {
        case 65:;
        case 66:;
        case 67:;
        case 68:;
        case 69:;
        case 70:;
        {
            d = (u64)((((u64)(c) - 'A') + (i64)10));
        }break;
        case 97:;
        case 98:;
        case 99:;
        case 100:;
        case 101:;
        case 102:;
        {
            d = (u64)((((u64)(c) - 'a') + (i64)10));
        }break;
        case 48:;
        case 49:;
        case 50:;
        case 51:;
        case 52:;
        case 53:;
        case 54:;
        case 55:;
        case 56:;
        case 57:;
        {
            d = ((u64)(c) - '0');
        }break;
        case 95:;
        case 39:;
        {
            goto L256 ;
        }break;
        default: {
            msysnewc_itemerror = (i64)1;
            goto L257 ;
        }
        } //SW
;
        if (((i64)(d) >= base)) {
            msysnewc_itemerror = (i64)1;
            goto L257 ;
        };
        aa = (u64)((((i64)(aa) * base) + (i64)(d)));
L256 :;
    }L257 :;
    ;
    if (!!((u64)(signd))) {
        return (i64)(-(aa));
    } else {
        return (i64)(aa);
    };
}

i64 msysnewc_m_read_i64(i64 fmt) {
    byte *  s;
    i64 length;
    if ((fmt==(i64)67) || (fmt==(i64)99)) {
        msysnewc_rd_lastpos = msysnewc_rd_pos;
        if (!!((u64)((*msysnewc_rd_pos)))) {
            return (i64)((*msysnewc_rd_pos++));
        } else {
            return (i64)0;
        };
    }else if ((fmt==(i64)84) || (fmt==(i64)116)) {
        return msysnewc_termchar;
    }else if ((fmt==(i64)69) || (fmt==(i64)101)) {
        return msysnewc_itemerror;
    };
    s = msysnewc_readitem(&length);
    if ((fmt==(i64)0) || (fmt==(i64)73) || (fmt==(i64)105)) {
        return msysnewc_strtoint(s,length,(i64)10);
    }else if ((fmt==(i64)66) || (fmt==(i64)98)) {
        return msysnewc_strtoint(s,length,(i64)2);
    }else if ((fmt==(i64)72) || (fmt==(i64)104)) {
        return msysnewc_strtoint(s,length,(i64)16);
    };
    return (i64)0;
}

double msysnewc_m_read_r64(i64 fmt) {
    byte str[512];
    byte *  s;
    i64 length;
    i32 numlength;
    double x;
    s = msysnewc_readitem(&length);
    if (((length == (i64)0) || (length >= (i64)512))) {
        return (double)0.;
    };
    memcpy((void *)(str),(void *)(s),(u64)(length));
    str[((length + (i64)1))-1] = (u64)0u;
    msysnewc_itemerror = (i64)0;
    if ((((i64)(sscanf((i8 *)(str),(i8 *)((byte*)"%lf%n"),&x,&numlength)) == (i64)0) || ((i64)(numlength) != length))) {
        x = (double)0.;
        msysnewc_itemerror = (i64)1;
    };
    return x;
}

void msysnewc_m_read_str(byte * dest,i64 destlen,i64 fmt) {
    byte *  s;
    i64 length;
    msysnewc_itemerror = (i64)0;
    if (((fmt == (i64)76) || (fmt == (i64)108))) {
        s = msysnewc_rd_pos;
        length = ((msysnewc_rd_buffer + msysnewc_rd_length) - msysnewc_rd_pos);
    } else {
        s = msysnewc_readitem(&length);
        if (((fmt == (i64)78) || (fmt == (i64)110))) {
            msysnewc_iconvlcn(s,length);
        };
    };
    if ((destlen > (i64)0)) {
        if ((length >= destlen)) {
            length = (destlen - (i64)1);
            msysnewc_itemerror = (i64)1;
        };
    };
    memcpy((void *)(dest),(void *)(s),(u64)(length));
    (*(dest + length)) = (u64)0u;
}

void msysnewc_readstr(byte * dest,i64 fmt,i64 destlen) {
    msysnewc_m_read_str(dest,destlen,fmt);
}

void msysnewc_rereadln(void) {
    msysnewc_rd_pos = msysnewc_rd_buffer;
    msysnewc_rd_lastpos = msysnewc_rd_pos;
}

void msysnewc_reread(void) {
    msysnewc_rd_pos = msysnewc_rd_lastpos;
}

i64 msysnewc_valint(byte * s,i64 fmt) {
    byte *  old_pos;
    byte *  old_lastpos;
    i64 aa;
    msysnewc_initreadbuffer();
    old_pos = msysnewc_rd_pos;
    old_lastpos = msysnewc_rd_lastpos;
    msysnewc_rd_pos = s;
    aa = msysnewc_m_read_i64(fmt);
    msysnewc_rd_pos = old_pos;
    msysnewc_rd_lastpos = old_lastpos;
    return aa;
}

double msysnewc_valreal(byte * s) {
    byte *  old_pos;
    byte *  old_lastpos;
    double x;
    msysnewc_initreadbuffer();
    old_pos = msysnewc_rd_pos;
    old_lastpos = msysnewc_rd_lastpos;
    msysnewc_rd_pos = s;
    x = msysnewc_m_read_r64((i64)0);
    msysnewc_rd_pos = old_pos;
    msysnewc_rd_lastpos = old_lastpos;
    return x;
}

static void msysnewc_iconvlcn(byte * s,i64 n) {
    i64 av_1;
    av_1 = n;
    while (av_1-- > 0) {
L258 :;
        (*s) = (u64)(tolower((i64)((i32)((*s)))));
        ++s;
L259 :;
    }L260 :;
    ;
}

static void msysnewc_iconvucn(byte * s,i64 n) {
    i64 av_1;
    av_1 = n;
    while (av_1-- > 0) {
L261 :;
        (*s) = (u64)(toupper((i64)((i32)((*s)))));
        ++s;
L262 :;
    }L263 :;
    ;
}

static void msysnewc_convlcstring(byte * s) {
    L264 :;
    while (!!((u64)((*s)))) {
        (*s) = (u64)(tolower((i64)((i32)((*s)))));
        ++s;
L265 :;
    }L266 :;
    ;
}

static void msysnewc_convucstring(byte * s) {
    L267 :;
    while (!!((u64)((*s)))) {
        (*s) = (u64)(toupper((i64)((i32)((*s)))));
        ++s;
L268 :;
    }L269 :;
    ;
}

i64 msysnewc_m_power_i64(i64 n,i64 a) {
    if ((n < (i64)0)) {
        return (i64)0;
    } else if ((n == (i64)0)) {
        return (i64)1;
    } else if ((n == (i64)1)) {
        return a;
    } else if (((n & (i64)1) == (i64)0)) {
        return msysnewc_m_power_i64((n / (i64)2),(a * a));
    } else {
        return (msysnewc_m_power_i64(((n - (i64)1) / (i64)2),(a * a)) * a);
    };
}

void msysnewc_m_intoverflow(void) {
    mlib_abortprogram((byte*)"Integer overflow detected");
}

void msysnewc_m_dotindex(u64 i,u64 a) {
    mlib_abortprogram((byte*)"DOT INDEX");
}

void msysnewc_m_dotslice(u64 j,u64 i,u64 a) {
    mlib_abortprogram((byte*)"DOT SLICE");
}

void msysnewc_m_popdotindex(u64 i,u64 * p,u64 x) {
    mlib_abortprogram((byte*)"POP DOT INDEX");
}

void msysnewc_m_popdotslice(u64 j,u64 i,u64 * p,u64 x) {
    mlib_abortprogram((byte*)"POP DOT SLICE");
}

i64 msysnewc_m_imin(i64 a,i64 b) {
    return (a<b?a:b);
}

i64 msysnewc_m_imax(i64 a,i64 b) {
    return (a>b?a:b);
}

double msysnewc_m_sign(double x) {
    if ((x > (double)0.)) {
        return (double)1.;
    } else if ((x < (double)0.)) {
        return (double)-1.;
    } else {
        return (double)0.;
    };
}

void oswindows_os_init(void) {
    oswindows_hconsole = GetStdHandle((u64)4294967285u);
    oswindows_hconsolein = GetStdHandle((u64)4294967286u);
    oswindows_lastkey.repeatcount = (u64)((i64)0);
    oswindows_keypending = (i64)0;
    SetConsoleCtrlHandler((void (*)(void))(0),(u64)1u);
    SetConsoleMode(oswindows_hconsole,(u64)3u);
    oswindows_init_flag = (i64)1;
}

i64 oswindows_os_execwait(byte * cmdline,i64 newconsole,byte * workdir) {
    u32 exitcode;
    i64 status;
    i64 cflags;
    struct oswindows_rstartupinfo si;
    struct oswindows_rprocess_information xpi;
    cflags = (i64)0;
    memset((void *)(&si),(i64)0,(u64)((i64)104));
    memset((void *)(&xpi),(i64)0,(u64)((i64)24));
    switch (newconsole) {
    case 0:;
    {
        cflags = (i64)32;
    }break;
    case 1:;
    {
        cflags = (i64)48;
    }break;
    case 2:;
    {
        cflags = (i64)48;
    }break;
    default: {
    }
    } //SW
;
    si.size = (u64)((i64)104);
    status = (i64)(CreateProcessA((byte *)(0),cmdline,0,0,(u64)1u,(u64)((u32)(cflags)),0,(byte *)(0),(void *)(&si),(void *)(&xpi)));
    if ((status == (i64)0)) {
        status = (i64)(GetLastError());
        msysnewc_m_print_startcon();
        msysnewc_m_print_str((byte*)"Winexec error:",NULL);
        msysnewc_m_print_i64(status,NULL);
        msysnewc_m_print_newline();
        msysnewc_m_print_end();
        ;
        return (i64)-1;
    };
    WaitForSingleObject(xpi.process,(u64)4294967295u);
    GetExitCodeProcess(xpi.process,(void *)(&exitcode));
    CloseHandle(xpi.process);
    CloseHandle(xpi.thread);
    return (i64)(exitcode);
}

i64 oswindows_os_execcmd(byte * cmdline,i64 newconsole) {
    struct oswindows_rstartupinfo si;
    struct oswindows_rprocess_information xpi;
    memset((void *)(&si),(i64)0,(u64)((i64)104));
    memset((void *)(&xpi),(i64)0,(u64)((i64)24));
    si.size = (u64)((i64)104);
    CreateProcessA((byte *)(0),cmdline,0,0,(u64)1u,(u64)((u32)(((i64)32 | (!!(newconsole)?(i64)16:(i64)0)))),0,(byte *)(0),(void *)(&si),(void *)(&xpi));
    CloseHandle(xpi.process);
    CloseHandle(xpi.thread);
    return (i64)1;
}

i64 oswindows_os_getch(void) {
    i64 k;
    k = (oswindows_os_getchx() & (i64)255);
    return k;
}

i64 oswindows_os_kbhit(void) {
    u32 count;
    if (!(!!(oswindows_init_flag))) {
        oswindows_os_init();
    };
    GetNumberOfConsoleInputEvents(oswindows_hconsolein,(void *)(&count));
    return ((i64)((u64)(count)) > (i64)1);
}

void oswindows_os_flushkeys(void) {
    FlushConsoleInputBuffer(oswindows_hconsolein);
}

void * oswindows_os_getconsolein(void) {
    return oswindows_hconsolein;
}

void * oswindows_os_getconsoleout(void) {
    return oswindows_hconsole;
}

void * oswindows_os_proginstance(void) {
    mlib_abortprogram((byte*)"PROGINST");
    return 0;
}

u64 oswindows_os_getdllinst(byte * name) {
    void *  hinst;
    hinst = LoadLibraryA(name);
    return (u64)(hinst);
}

void * oswindows_os_getdllprocaddr(i64 hinst,byte * name) {
    return GetProcAddress((void *)(hinst),name);
}

void oswindows_os_initwindows(void) {
    oswindows_os_init();
    oswindows_os_gxregisterclass((byte*)"pcc001");
}

void oswindows_os_gxregisterclass(byte * classname) {
    struct oswindows_rwndclassex r;
    static byte registered;
    if (!!((u64)(registered))) {
        return;
    };
    memset((void *)(&r),(i64)0,(u64)((i64)80));
    r.size = (u64)((i64)80);
    r.style = (u64)((i64)40);
    r.wndproc = (void (*)(void))(&oswindows_mainwndproc);
    r.instance = 0;
    r.icon = 0;
    r.cursor = LoadCursorA(0,(byte *)((void *)((i64)32512)));
    r.background = (void *)((i64)16);
    r.menuname = (byte *)(0);
    r.classname = classname;
    r.iconsm = 0;
    if (((i64)((u64)(RegisterClassExA((void *)(&r)))) == (i64)0)) {
        msysnewc_m_print_startcon();
        msysnewc_m_print_str(classname,NULL);
        msysnewc_m_print_ptr(GetLastError,NULL);
        msysnewc_m_print_newline();
        msysnewc_m_print_end();
        ;
        mlib_abortprogram((byte*)"Registerclass error");
    };
    registered = (u64)((i64)1);
}

CALLBACK i64 oswindows_mainwndproc(void * hwnd,u32 message,u64 wparam,u64 lparam) {
    struct oswindows_rmsg m;
    i64 result;
    static i64 count = (i64)0;
    m.hwnd = hwnd;
    m.message = (u64)(message);
    m.wparam = wparam;
    m.lparam = lparam;
    m.pt.x = (i64)0;
    m.pt.y = (i64)0;
    if (!!(oswindows_wndproc_callbackfn)) {
        result = ((*oswindows_wndproc_callbackfn))((void *)(&m));
    } else {
        result = (i64)0;
    };
    if (((i64)((u64)(m.message)) == (i64)2)) {
        return (i64)0;
    };
    if (!(!!(result))) {
        return (i64)(DefWindowProcA(hwnd,(u64)(message),wparam,lparam));
    } else {
        return (i64)0;
    };
}

static void oswindows_timerproc(void * hwnd,i64 msg,i64 id,i64 time) {
    msysnewc_m_print_startcon();
    msysnewc_m_print_str((byte*)"TIMERPROC",NULL);
    msysnewc_m_print_newline();
    msysnewc_m_print_end();
    ;
}

void oswindows_os_setmesshandler(void * addr) {
    oswindows_wndproc_callbackfn = (i64 (*)(void *))(addr);
}

i64 oswindows_os_getchx(void) {
    i64 count;
    i64 charcode;
    i64 keyshift;
    i64 keycode;
    i64 altdown;
    i64 ctrldown;
    i64 shiftdown;
    i64 capslock;
    if (!(!!(oswindows_init_flag))) {
        oswindows_os_init();
    };
    if (!!(oswindows_keypending)) {
        oswindows_lastkey = oswindows_pendkey;
        oswindows_keypending = (i64)0;
    } else {
        if (((i64)((u64)(oswindows_lastkey.repeatcount)) == (i64)0)) {
            L270 :;
            do {
                count = (i64)0;
                ReadConsoleInputA(oswindows_hconsolein,(void *)(&oswindows_lastkey),(u64)1u,(void *)(&count));
L271 :;
            } while (!(((i64)((u64)(oswindows_lastkey.eventtype)) == (i64)1) && ((i64)((u64)(oswindows_lastkey.keydown)) == (i64)1)));L272 :;
            ;
        };
    };
    altdown = (!!(((i64)((u64)(oswindows_lastkey.controlkeystate)) & (i64)3))?(i64)1:(i64)0);
    ctrldown = (!!(((i64)((u64)(oswindows_lastkey.controlkeystate)) & (i64)12))?(i64)1:(i64)0);
    shiftdown = (!!(((i64)((u64)(oswindows_lastkey.controlkeystate)) & (i64)16))?(i64)1:(i64)0);
    capslock = (!!(((i64)((u64)(oswindows_lastkey.controlkeystate)) & (i64)128))?(i64)1:(i64)0);
    --oswindows_lastkey.repeatcount;
    charcode = (i64)(oswindows_lastkey.asciichar);
    keycode = ((i64)((u64)(oswindows_lastkey.virtualkeycode)) & (i64)255);
    if ((charcode < (i64)0)) {
        if ((charcode < (i64)-128)) {
            charcode = (i64)0;
        } else {
            charcode += (i64)256;
        };
    };
    if (((!!(altdown) && !!(ctrldown)) && (charcode == (i64)166))) {
        altdown = (ctrldown = (i64)0);
    } else {
        if ((!!(altdown) || !!(ctrldown))) {
            charcode = (i64)0;
            if (((keycode >= (i64)65) && (keycode <= (i64)90))) {
                charcode = (keycode - (i64)64);
            };
        };
    };
    keyshift = ((((capslock << (i64)3) | (altdown << (i64)2)) | (ctrldown << (i64)1)) | shiftdown);
    return (((keyshift << (i64)24) | (keycode << (i64)16)) | charcode);
}

byte * oswindows_os_getos(void) {
    if (((i64)64 == (i64)32)) {
        return (byte*)"W32";
    } else {
        return (byte*)"W64";
    };
}

i64 oswindows_os_gethostsize(void) {
    return (i64)64;
}

i64 oswindows_os_shellexec(byte * opc,byte * file) {
    return (i64)(system((i8 *)(file)));
}

void oswindows_os_sleep(i64 a) {
    Sleep((u64)((u32)(a)));
}

void * oswindows_os_getstdin(void) {
    return fopen((i8 *)((byte*)"con"),(i8 *)((byte*)"rb"));
}

void * oswindows_os_getstdout(void) {
    return fopen((i8 *)((byte*)"con"),(i8 *)((byte*)"wb"));
}

byte * oswindows_os_gethostname(void) {
    static byte name[300];
    GetModuleFileNameA(0,name,(u64)300u);
    strcat((i8 *)(name),(i8 *)((byte*)"/"));
    return name;
}

byte * oswindows_os_getmpath(void) {
    return (byte*)"C:\\m\\";
}

void oswindows_os_exitprocess(i64 x) {
    exit(x);
}

i64 oswindows_os_clock(void) {
    return (i64)(clock());
}

i64 oswindows_os_getclockspersec(void) {
    return (i64)1000;
}

i64 oswindows_os_iswindows(void) {
    return (i64)1;
}

i64 oswindows_os_filelastwritetime(byte * filename) {
    void *  f;
    i64 ctime;
    i64 atime;
    i64 wtime;
    if ((filename == 0)) {
        return (i64)1;
    };
    f = CreateFileA(filename,(u64)2147483648u,(u64)1u,0,(u64)3u,(u64)3u,0);
    if (((i64)(f) == (i64)-1)) {
        return (i64)0;
    };
    GetFileTime(f,(void *)(&ctime),(void *)(&atime),(void *)(&wtime));
    CloseHandle(f);
    return wtime;
}

void oswindows_os_getsystime(struct oswindows_rsystemtime * tm) {
    GetLocalTime(tm);
}

void oswindows_os_messagebox(byte * s,byte * t) {
    MessageBoxA((i64)0,s,t,(i64)0);
}

i64 oswindows_os_hpcounter(void) {
    i64 a;
    QueryPerformanceCounter(&a);
    return a;
}

i64 oswindows_os_hpfrequency(void) {
    i64 a;
    QueryPerformanceFrequency(&a);
    return a;
}

void oswindows_os_peek(void) {
    i64 ticks;
    static i64 lastticks;
    byte m[100];
    ticks = (i64)(GetTickCount());
    if (((ticks - lastticks) >= (i64)1000)) {
        lastticks = ticks;
        PeekMessageA((void *)(&m),(void * *)(0),(u64)0u,(u64)0u,(u64)0u);
    };
}


/* ********** End of C Code ********** */
