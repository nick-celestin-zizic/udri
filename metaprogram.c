#define NOBUILD_IMPLEMENTATION
#include "./lib/nobuild.h"

// TODO factor out platform specific stuff when I add more platform layers
#define PLATFORM "linux"
#define CC "gcc"
#define DEBUG_FLAGS "-g"
#define LIBS "-lX11", "-lGL", "-lGLU", "-lGLEW", "-lm"
#define RUN_IN_TERM CMD("st", "-e", EXE)
#define DEBUG_EXE CMD("st", "-e", "gdb", "--tui", EXE)
#define PROFILE_EXE CHAIN(CHAIN_CMD("mv", "gmon.out", PATH("bin")),\
                          CHAIN_CMD("gprof", EXE, PATH("bin", "gmon.out")),\
                          OUT("./bin/profile"))

#define CFLAGS "-std=gnu11", "-Wall", "-Wextra", "-pedantic", /* "-fms-extensions",*/ "-I./libs", "-I./src"
#define INTERNAL_FLAGS DEBUG_FLAGS, "-DUDRI_INTERNAL"
#define RELEASE_FLAGS "-ofast", "-DUDRI_RELEASE"
#define EXE_NAME CONCAT(PLATFORM, "_udri")
#define EXE PATH("bin", EXE_NAME)
#define ENTRY_POINT PATH("src", CONCAT(EXE_NAME, ".c"))

void usage (FILE *out) {
  fprintf(out,
          "usage: ./build [help|run|debug|profile|term|release|codegen]\n"
          "  help    - prints this message and exits\n"
          "  run     - compile and run program in internal mode\n"
          "  debug   - compile and run the program in a debugger\n"
          "  profile - compile and run the program in a profiler\n"
          "  term    - compile and run program in a terminal\n"
          "  release - compile the program in release mode\n"
          "  codegen - generate code and don't compile/run main program.\n");
}

void generate_code () {
  CMD(CC, PATH("src", "udri_generate_la.c"), "-o", PATH("bin", "lagen"));
  CMD(PATH("bin", "lagen"));
}

int main (int argc, char **argv) {
  GO_REBUILD_URSELF(argc, argv);
  
  generate_code();
  
  if (argc == 1) {
    CMD(CC, CFLAGS, INTERNAL_FLAGS, "-o", EXE, ENTRY_POINT, LIBS);
  } else if (argc == 2) {
    if (strcmp(argv[1], "codegen") == 0) {
      return 0;
      
    } else if (strcmp(argv[1], "help") == 0) {
      usage(stdout);
      return 0;
      
    } else if (strcmp(argv[1], "run") == 0) {    
      CMD(CC, CFLAGS, INTERNAL_FLAGS, "-o", EXE, ENTRY_POINT, LIBS);
      CMD(EXE);
      
    } else if (strcmp(argv[1], "debug") == 0) {
      CMD(CC, CFLAGS, INTERNAL_FLAGS, "-o", EXE, ENTRY_POINT, LIBS);
      DEBUG_EXE;
      
    } else if (strcmp(argv[1], "profile") == 0) {
      CMD(CC, CFLAGS, INTERNAL_FLAGS, "-pg", "-o", EXE, ENTRY_POINT, LIBS);
      CMD(EXE);
      PROFILE_EXE;
      
    } else if (strcmp(argv[1], "term") == 0) {
      CMD(CC, CFLAGS, INTERNAL_FLAGS, "-o", EXE, ENTRY_POINT, LIBS);
      RUN_IN_TERM;
      
    } else if (strcmp(argv[1], "release") == 0) {
      // TODO bake constants and pre-compile shaders
      CMD(CC, CFLAGS, RELEASE_FLAGS, "-o", EXE, ENTRY_POINT, LIBS);
      
    } else {
      usage(stderr);
      return 1;
    }
  }
}
