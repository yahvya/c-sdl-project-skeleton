#if !defined(SDLH_UTIL_H)
#define SDLH_UTIL_H
    #include "./structs.h"

    /**
     * @brief chaine un nouvel élement à libérer dans la liste
     * @param baseList la liste à remplir
     * @param toFreeAfter l'élement à libérer
     * @return la nouvelle liste ou la liste passée en cas d'erreur
    */
    struct ToFree* addElementToFree(struct ToFree* baseList,void* toFreeAfter);

    /**
     * @brief libère les élements de la liste ainsi que la liste
     * @param toFree la liste à libérer
     * @param freeCallable fonction à appeller pour libérer la ressource contenu, si NULL alors free par défaut appliqué 
    */
    void freeList(struct ToFree* toFree,void (*freeCallable)(void*) );

    /**
     * @brief libère les données concernant l'image passée
    */
    void freeSDLImage(void* imageSurface);
#endif