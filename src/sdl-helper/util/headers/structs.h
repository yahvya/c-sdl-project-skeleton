#if !defined(SDLH_UTIL_STRUCTS_H)
#define SDLH_UTIL_STRUCTS_H

    /**
     * @struct ToFree
     * @brief représente une liste d'élements à désalouer
     * @param toFree
     * @param nextElementToFree
    */
    typedef struct ToFree{
        void* toFree;
        struct ToFree* nextElementToFree;
    }ToFree;
#endif