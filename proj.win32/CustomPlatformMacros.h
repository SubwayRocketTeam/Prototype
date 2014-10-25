

#define CREATE_SPRITE_FUNC(__TYPE__) \
	static __TYPE__* create() \
{ \
	__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->init()) \
	{ \
	pRet->autorelease(); \
	return pRet; \
	} \
else \
	{ \
	delete pRet; \
	pRet = NULL; \
	return NULL; \
	} \
} \
	static __TYPE__* create(char* filename) \
{ \
	__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->initWithFile(filename)) \
{ \
	pRet->autorelease(); \
	return pRet; \
} \
else \
{ \
	delete pRet; \
	pRet = NULL; \
	return NULL; \
} \
}