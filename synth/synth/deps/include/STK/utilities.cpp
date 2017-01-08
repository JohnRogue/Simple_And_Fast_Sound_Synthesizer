// Miscellaneous parsing and error functions for use with STK demo program.
//
// Gary P. Scavone, 1999.

#include <cstring>
#include "utilities.h"

// STK Instrument Classes
#include "Clarinet.h"


using namespace stk;

#define NUM_INSTS 28

// The order of the following list is important.  The location of a particular
// instrument in the list should correspond to that instrument's ProgramChange
// number (i.e. Clarinet = ProgramChange 0).
char insts[NUM_INSTS][10] = { "Clarinet"};

int voiceByNumber(int number, Instrmnt **instrument)
{
  /*int temp = number;
  
  if     (number==0)  *instrument = new Clarinet(10.0);


  else {
    printf("\nUnknown instrument or program change requested!\n");
    temp = -1;
  }*/
  *instrument = new Clarinet(10.0);
  return 0;
}

//int voiceByName(char *name, Instrmnt **instrument)
//{
//  int i = 0, temp = -1, notFound = 1;;
//
// /* while ( i < NUM_INSTS && notFound ) {
//    if ( !strcmp(name, insts[i]) ) {
//      notFound = 0;
//      temp = voiceByNumber(i, instrument);
//    }
//    i++;
//  }
//
//  if (temp < 0) 
//    printf("\nUnknown instrument or program change requested!\n");*/
//  temp = voiceByNumber(i, instrument);
//  return temp;
//}
///////////////////////////////////////////////////////////////�MIECI///////////////////////////////////////////////////////////////////////////////////////
//void usage(char *function) {
//  // Error function in case of incorrect command-line argument specifications
//  int i, j;
//
//  printf("\nuseage: %s Instrument flag(s) \n", function);
//  printf("        where flag = -s RATE to specify a sample rate,\n");
//  printf("        -n NUMBER specifies the number of voices to allocate,\n");
//  printf("        -ow <file name> for .wav audio output file,\n");
//  printf("        -os <file name> for .snd audio output file,\n");
//  printf("        -om <file name> for .mat audio output file,\n");
//  printf("        -oa <file name> for .aif audio output file,\n");
//#if defined(__STK_REALTIME__)
//  printf("        -or for realtime audio output,\n");
//#endif
//  printf("        -if <file name> to read control input from SKINI file,\n");
//#if defined(__STK_REALTIME__)
//  printf("        -ip for realtime control input by pipe,\n");
//  printf("        -im <port> for realtime control input by MIDI (virtual port = 0, default = 1),\n");
//#endif
//  printf("        and Instrument = one of these:\n");
//  for ( i=0; i<NUM_INSTS; i+=8 ) {
//    for ( j=0; j<8 && (i+j)<NUM_INSTS; j++ ) {
//      printf("%s ",insts[i+j]);
//    }
//    printf("\n");
//  }
//  printf("\nSimultaneous multiple output types are supported.\n");
//  printf("Likewise, simultaneous control input types are supported.\n");
//  printf("SKINI formatted scorefiles can be piped or redirected\n");
//  printf("to %s, though realtime control flags should be omitted\n", function);
//  printf("when doing so. If the optional <file names> are not\n");
//  printf("specified, default names will be indicated.  Each flag\n");
//  printf("must include its own '-' sign.\n\n");
//  exit(0);
//}
//
//int checkArgs(int nArgs, char *args[])
//{
//  int w, i = 2, j = 0;
//  int nWvOuts = 0;
//  char flags[2][50] = {""};
//  bool realtime = false;
//
//  if (nArgs < 3 || nArgs > 22) usage(args[0]);
//
//  while (i < nArgs) {
//    if (args[i][0] == '-') {
//      if (args[i][1] == 'o') {
//        if ( args[i][2] == 'r' ) realtime = true;
//        if ( (args[i][2] == 's') || (args[i][2] == 'w') ||
//             (args[i][2] == 'm') || (args[i][2] == 'a') )
//          nWvOuts++;
//        flags[0][j] = 'o';
//        flags[1][j++] = args[i][2];
//      }
//      else if (args[i][1] == 'i') {
//        if ( (args[i][2] != 'p') && (args[i][2] != 'm') &&
//             (args[i][2] != 'f') ) usage(args[0]);
//        flags[0][j] = 'i';
//        flags[1][j++] = args[i][2];
//      }
//      else if (args[i][1] == 's' && (i+1 < nArgs) && args[i+1][0] != '-' ) {
//        Stk::setSampleRate( atoi(args[i+1]) );
//        flags[0][j++] = 's';
//      }
//      else if (args[i][1] == 'n' && (i+1 < nArgs) && args[i+1][0] != '-' ) {
//        flags[0][j++] = 'n';
//      }
//      else usage(args[0]);
//    }
//    i++;
//  }
//
//  // Check for multiple flags of the same type
//  for ( i=0; i<=j; i++ ) {
//    w = i+1;
//    while  (w <= j ) {
//      if ( flags[0][i] == flags[0][w] && flags[1][i] == flags[1][w] ) {
//        printf("\nError: Multiple command line flags of the same type specified.\n\n");
//        usage(args[0]);
//      }
//      w++;
//    }
//  }
//
//  // Make sure we have at least one output type
//  if ( nWvOuts < 1 && !realtime ) usage(args[0]);
//
//  return nWvOuts;
//}
//
//int countVoices(int nArgs, char *args[])
//{
//  int i = 2, nInstruments = 1;
//
//  while ( i < nArgs ) {
//    if ( strncmp( args[i], "-n", 2) == 0 ) {
//      if ( i+1 < nArgs && args[i+1][0] != '-' ) {
//        nInstruments = atoi( args[i+1] );
//        if ( nInstruments < 1 ) nInstruments = 1;
//      }
//    }
//    i++;
//  }
//
//  return nInstruments;
//}
//
///*bool parseArgs(int nArgs, char *args[], WvOut **output, Messager& messager)
//{
//
//}
//*/
//bool parseArgs(int nArgs, char *args[], WvOut **output, Messager& messager)
//{
//	if (!messager.startMidiInput()) exit(0);
//
//
//
//
//
//	return true;
//}
//
////bool parseArgs(int nArgs, char *args[], WvOut **output, Messager& messager)
////{
////  int i = 2, j = 0, nWvIns = 0;
////  bool realtime = false;
////  char fileName[256];
////
////  while (i < nArgs) {
////    if ( (args[i][0] == '-') && (args[i][1] == 'i') ) {
////      switch(args[i][2]) {
////
////      case 'f':
////        strcpy(fileName,args[++i]);
////        if ( !messager.setScoreFile( fileName ) ) exit(0);
////        nWvIns++;
////        break;
////
////      case 'p':
////#if defined(__STK_REALTIME__)
////        if ( !messager.startStdInput() ) exit(0);
////        nWvIns++;
////        break;
////#else
////        usage(args[0]);
////#endif
////
////      case 'm':
////#if defined(__STK_REALTIME__)
////        // Check for an optional MIDI port argument.
////        if ((i+1 < nArgs) && args[i+1][0] != '-') {
////          int port = atoi(args[++i]);
////          if ( !messager.startMidiInput( port-1 ) ) exit(0);
////        }
////        else if ( !messager.startMidiInput() ) exit(0);
////        nWvIns++;
////        break;
////#else
////        usage(args[0]);
////#endif
////
////      default:
////        usage(args[0]);
////        break;
////      }
////    }
////    else if ( (args[i][0] == '-') && (args[i][1] == 'o') ) {
////      switch(args[i][2]) {
////
////      case 'r':
////#if defined(__STK_REALTIME__)
////        realtime = true;
////        break;
////#else
////        usage(args[0]);
////#endif
////
////      case 'w':
////        if ((i+1 < nArgs) && args[i+1][0] != '-') {
////          i++;
////          strcpy(fileName,args[i]);
////        }
////        else strcpy(fileName,"testwav");
////        output[j] = new FileWvOut(fileName, 1, FileWrite::FILE_WAV );
////        j++;
////        break;
////          
////      case 's':
////        if ((i+1 < nArgs) && args[i+1][0] != '-') {
////          i++;
////          strcpy(fileName,args[i]);
////        }
////        else strcpy(fileName,"testsnd");
////        output[j] = new FileWvOut(fileName,1, FileWrite::FILE_SND);
////        j++;
////        break;
////          
////      case 'm':
////        if ((i+1 < nArgs) && args[i+1][0] != '-') {
////          i++;
////          strcpy(fileName,args[i]);
////        }
////        else strcpy(fileName,"testmat");
////        output[j] = new FileWvOut(fileName,1, FileWrite::FILE_MAT);
////        j++;
////        break;
////
////      case 'a':
////        if ((i+1 < nArgs) && args[i+1][0] != '-') {
////          i++;
////          strcpy(fileName,args[i]);
////        }
////        else strcpy(fileName,"testaif");
////        output[j] = new FileWvOut(fileName,1, FileWrite::FILE_AIF );
////        j++;
////        break;
////          
////      default:
////        usage(args[0]);
////        break;
////      }
////    }
////    i++;
////  }
////
////  if ( nWvIns == 0 ) {
////#if defined(__STK_REALTIME__)
////    if ( !messager.startStdInput() ) exit(0);
////#else
////    printf("\nError: The -if file input flag must be specified for non-realtime use.\n\n");
////    usage(args[0]);
////#endif
////  }
////
////  return realtime;
////}
