#include "cleaner.h"

file_fingerprint* ffpnew(const char* filepath,off_t filesize, mode_t filetype){
    file_fingerprint* ffp = (file_fingerprint *)malloc(sizeof(file_fingerprint));
    ffp->filepath = filepath;
    ffp->filetype = filetype;
    ffp->filesize = filesize;
    return ffp;
}

void ffpfree(file_fingerprint* ffp){
    free((char *)ffp->filepath);
    if(ffp->md5){
        free(ffp->md5);
    }
}

// compar points to a comparison routine, which takes pointers to two items.
int ffp_compare (const void* ffp1, const void* ffp2){
    file_fingerprint* fp1 = (file_fingerprint *) ffp1;
    file_fingerprint* fp2 = (file_fingerprint *) ffp2;
    if (fp1->filesize>fp2->filesize){
        return 1;
    }else if(fp1->filesize<fp2->filesize){
        return -1;
    }else{
        return 0;
    }
}

