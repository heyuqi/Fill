/* ========================================================================== //
//                                                                            //
//      Copyright (C) C3P Engineering Software International 2007 - 2015      //
//                            All Rights Reserved                             //
//                       Proprietary and Trade Secret                         //
//                                                                            //
// ========================================================================== */

//==============================================================================
// Declarations
//==============================================================================

#include <stdio.h>
#include <stdlib.h>

//==============================================================================
// Implementations
//==============================================================================

int main () {
  size_t buffer_size = 1024 * 1024;
  unsigned char *buffer = (unsigned char *) calloc (buffer_size, sizeof (unsigned char));
  char *file_name = (char *) calloc (1024, sizeof (unsigned char));
  FILE *stream = NULL;
  int file_id, buffer_id, last_file_id;
  size_t written_size;

  // Fill data.
  for (file_id = 0; ; ++file_id) {
    sprintf (file_name, "SOLID%02X", file_id);

    stream = fopen (file_name, "wb");
    if (! stream) {
      printf ("\n");
      break;
    }

    for (buffer_id = 0; buffer_id < 2 * 1024; ++buffer_id) {
      written_size = fwrite (buffer, sizeof (unsigned char), buffer_size, stream);
      printf ("%s: %.2f GB WRITTEN.\r", file_name, buffer_id / 1024.f);

      if (written_size != buffer_size) break;
    }

    fclose (stream);
    printf ("\n");

    if (written_size != buffer_size) break;
  }

  // Remove the file.
  last_file_id = file_id;
  for (file_id = 0; file_id <= last_file_id; ++file_id) {
    sprintf (file_name, "SOLID%02X", file_id);
    remove (file_name);
  }

  free (buffer);
  free (file_name);

  return 0;
}
