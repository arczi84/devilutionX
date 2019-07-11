#include <SDL.h>
#include "sdl1_wrapper.h"
#include <SDL_video.h>
#include <SDL_audio.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SDL_Window {
    const void *magic;
    Uint32 id;
    char *title;
    SDL_Surface *icon;
    int x, y;
    int w, h;
    int min_w, min_h;
    int max_w, max_h;
    Uint32 flags;
    Uint32 last_fullscreen_flags;

    /* Stored position and size for windowed mode */
    SDL_Rect windowed;

    SDL_DisplayMode fullscreen_mode;

    float brightness;
    Uint16 *gamma;
    Uint16 *saved_gamma;        /* (just offset into gamma) */

    SDL_Surface *surface;
    SDL_bool surface_valid;

    SDL_bool is_hiding;
    SDL_bool is_destroying;

    SDL_WindowShaper *shaper;

    SDL_HitTest hit_test;
    void *hit_test_data;

    SDL_WindowUserData *data;

    void *driverdata;

    SDL_Window *prev;
    SDL_Window *next;
};

struct SDL_WindowShaper {
    /* The window associated with the shaper */
    SDL_Window *window;

    /* The user's specified coordinates for the window, for once we give it a shape. */
    Uint32 userx,usery;

    /* The parameters for shape calculation. */
    SDL_WindowShapeMode mode;

    /* Has this window been assigned a shape? */
    SDL_bool hasshape;

    void *driverdata;
};

void SDL_RenderGetScale(SDL_Renderer* renderer, float* scaleX, float* scaleY)
{
}

void SDL_GetWindowSize(SDL_Window* window, int* w, int* h)
{
}

void SDL_GetWindowPosition(SDL_Window* window,  int* x, int* y)
{
}

void SDL_EnableScreenSaver(void)
{
}

void SDL_DisableScreenSaver(void)
{
}

SDL_bool SDL_SetHint(const char* name, const char* value)
{
    return (SDL_bool)1;
}

int SDL_ShowSimpleMessageBox(Uint32      flags, const char* title, const char* message, SDL_Window* window)
{
    return 1;
}

void SDL_RenderGetViewport(SDL_Renderer* renderer, SDL_Rect* rect)
{

}

SDL_Surface* SDL_CreateRGBSurfaceWithFormatFrom(void*  pixels,
                                                int    width,
                                                int    height,
                                                int    depth,
                                                int    pitch,
                                                Uint32 format)
{
    Uint32 rmask, gmask, bmask, amask;

    /* SDL interprets each pixel as a 32-bit number, so our masks must depend
       on the endianness (byte order) of the machine */
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif

    return SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rmask, gmask, bmask, amask);
}

int SDL_RenderSetLogicalSize(SDL_Renderer* renderer, int w, int h)
{
	return 1;
}

SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags)
{
	auto* window = new SDL_Window;

#ifdef __AMIGA__
	window->surface = SDL_SetVideoMode(w, h, 16, SDL_SWSURFACE | SDL_FULLSCREEN);
#else
    window->surface = SDL_SetVideoMode(w, h, 16, SDL_HWSURFACE);
#endif
	return window;
}

void SDL_DestroyWindow(SDL_Window* window)
{
	SDL_FreeSurface(window->surface);
}

SDL_Surface* SDL_GetWindowSurface(SDL_Window* window)
{
	if (window)		
		return window->surface;
	else
		return NULL;
}

int SDL_UpdateWindowSurface(SDL_Window* window)
{
	SDL_Flip(window->surface);
}

SDL_Renderer* SDL_CreateRenderer(SDL_Window* window,
                                 int         index,
                                 Uint32      flags)
{
	return window->surface;
}

int SDL_SetRenderDrawColor(SDL_Renderer* renderer,
                           Uint8         r,
                           Uint8         g,
                           Uint8         b,
                           Uint8         a)
{
	SDL_FillRect( renderer, NULL, SDL_MapRGBA( renderer->format, r, g, b, a) );
}

SDL_Texture* SDL_CreateTextureFromSurface(SDL_Renderer* renderer,
                                          SDL_Surface*  surface)
{
	if( renderer != nullptr )
	{
		//Create an optimized image
		renderer = SDL_DisplayFormat( surface );
		return renderer;
	}
}

SDL_AudioDeviceID SDL_OpenAudioDevice(const char* device, int iscapture,
                                      const SDL_AudioSpec* desired,
                                      SDL_AudioSpec*       obtained,
                                      int                  allowed_changes)
{

  return SDL_OpenAudio(const_cast<SDL_AudioSpec*>(desired), const_cast<SDL_AudioSpec*>(obtained));

}

void SDL_CloseAudioDevice(SDL_AudioDeviceID dev)
{
    SDL_CloseAudio();
}

void SDL_SetWindowTitle(SDL_Window* window, const char* title)
{
    SDL_WM_SetCaption(title, "");
}

void SDL_SetWindowPosition(SDL_Window* window, int x, int y)
{

}

void SDL_PauseAudioDevice(SDL_AudioDeviceID dev, int pause_on)
{
    SDL_PauseAudio(pause_on);
}

Uint32 SDL_GetWindowPixelFormat(SDL_Window* window)
{
    return SDL_PIXELFORMAT_RGB565;
}

SDL_bool SDL_IsScreenSaverEnabled(void)
{
    return (SDL_bool)1;
}

SDL_bool SDL_PointInRect(const SDL_Point* p, const SDL_Rect*  r)
{
    SDL_Cursor* cursor = SDL_GetCursor();

    if (cursor->area.x == p->x && cursor->area.y == p->y)
        return SDL_TRUE;
    else
        return SDL_FALSE;
}


int SDL_BlitScaled(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect)
{
    return SDL_BlitSurface(src, const_cast<SDL_Rect*>(srcrect), dst, dstrect);
}

void SDL_ClearQueuedAudio(SDL_AudioDeviceID dev)
{

}

void SDL_ShowWindow(SDL_Window* window)
{

}

const Uint8* SDL_GetKeyboardState(int* numkeys)
{

}

void SDL_StopTextInput(void)
{

}

void SDL_StartTextInput(void)
{

}

void SDL_HideWindow(SDL_Window* window)
{

}

int SDL_GetRendererOutputSize(SDL_Renderer* renderer, int* w, int* h)
{
    return 0;
}

void SDL_WarpMouseInWindow(SDL_Window* window, int x, int y)
{
    SDL_WarpMouse(x, y);
}

SDL_Surface* SDL_ConvertSurfaceFormat(SDL_Surface* src, Uint32 pixel_format, Uint32 flags)
{
    return SDL_ConvertSurface(src, (SDL_PixelFormat*)pixel_format, flags);
}

SDL_bool SDL_IsTextInputActive(void)
{
    return (SDL_bool)0;
}

int SDL_GetCurrentDisplayMode(int displayIndex, SDL_DisplayMode* mode)
{
    return 0;
}

int SDL_UpdateTexture(SDL_Texture* texture, const SDL_Rect* rect, const void* pixels, int pitch)
{
    return 0;
}

SDL_Texture* SDL_CreateTexture(SDL_Renderer* renderer, Uint32 format, int access, int w, int h)
{
    return SDL_CreateRGBSurface(renderer->flags, w, h, 16, renderer->format->Rmask, renderer->format->Gmask, renderer->format->Bmask, renderer->format->Amask);
}

int SDL_SetWindowInputFocus(SDL_Window* window)
{
	return 0;
}

void SDL_DestroyTexture(SDL_Texture* texture)
{
	SDL_FreeSurface(texture);
}

void SDL_DestroyRenderer(SDL_Renderer* Renderer)
{
	SDL_FreeSurface(Renderer);
}

int SDL_RenderClear(SDL_Renderer* renderer)
{
	return 0;
}

int SDL_RenderCopy(SDL_Renderer*   renderer,
                   SDL_Texture*    texture,
                   const SDL_Rect* srcrect,
                   const SDL_Rect* dstrect)
{
   //Blit the surface
    SDL_BlitSurface( texture, NULL, renderer, NULL );
}

void SDL_RenderPresent(SDL_Renderer* renderer)
{
	SDL_Flip(renderer);
}

void SDL_Log(const char *fmt, ...) {

	printf("%s\n", fmt);
}

int SDL_SetSurfacePalette(SDL_Surface* surface, SDL_Palette* palette)
{
    return SDL_SetPalette(surface, surface->flags, palette->colors, 0, palette->ncolors);
}

SDL_Palette *
SDL_AllocPalette(int ncolors)
{
    SDL_Palette *palette;

    /* Input validation */
    if (ncolors < 1) {
      //SDL_InvalidParamError("ncolors");
      return NULL;
    }

    palette = (SDL_Palette *) SDL_malloc(sizeof(*palette));
    if (!palette) {
        SDL_OutOfMemory();
        return NULL;
    }
    palette->colors =
        (SDL_Color *) SDL_malloc(ncolors * sizeof(*palette->colors));
    if (!palette->colors) {
        SDL_free(palette);
        return NULL;
    }
    palette->ncolors = ncolors;
    //palette->version = 1;
    //palette->refcount = 1;

    SDL_memset(palette->colors, 0xFF, ncolors * sizeof(*palette->colors));

    return palette;
}

int
SDL_SetPixelFormatPalette(SDL_PixelFormat * format, SDL_Palette *palette)
{
    if (!format) {
        SDL_SetError("SDL_SetPixelFormatPalette() passed NULL format");
        return 0;
    }

    if (palette && palette->ncolors > (1 << format->BitsPerPixel)) {
        SDL_SetError("SDL_SetPixelFormatPalette() passed a palette that doesn't match the format");
        return 0;
    }

    if (format->palette == palette) {
        return 0;
    }

    if (format->palette) {
        SDL_FreePalette(format->palette);
    }

    format->palette = palette;
/*
    if (format->palette) {
        ++format->palette->refcount;
    }
*/
    return 0;
}

int
SDL_SetPaletteColors(SDL_Palette * palette, const SDL_Color * colors,
                     int firstcolor, int ncolors)
{
    int status = 0;

    /* Verify the parameters */
    if (!palette) {
        return -1;
    }
    if (ncolors > (palette->ncolors - firstcolor)) {
        ncolors = (palette->ncolors - firstcolor);
        status = -1;
    }

    if (colors != (palette->colors + firstcolor)) {
        SDL_memcpy(palette->colors + firstcolor, colors,
                   ncolors * sizeof(*colors));
    }
    /*
    ++palette->version;
    if (!palette->version) {
        palette->version = 1;
    }
*/
    return status;
}

void
SDL_FreePalette(SDL_Palette * palette)
{
    if (!palette) {
        SDL_SetError("palette error");
        return;
    }
    /*
    if (--palette->refcount > 0) {
        return;
    }
    */
    SDL_free(palette->colors);
    SDL_free(palette);
}

/*
 * Create an empty RGB surface of the appropriate depth using the given
 * enum SDL_PIXELFORMAT_* format
 */
SDL_Surface *
SDL_CreateRGBSurfaceWithFormat(Uint32 flags, int width, int height, int depth,
                               Uint32 format)
{
    SDL_Surface *surface;

    /* The flags are no longer used, make the compiler happy */
    (void)flags;

    /* Allocate the surface */
    surface = (SDL_Surface *) SDL_calloc(1, sizeof(*surface));
    if (surface == nullptr) {
        SDL_OutOfMemory();
        return nullptr;
    }

    surface->format = (SDL_PixelFormat*)format; //SDL_AllocFormat(format);
    if (!surface->format) {
        SDL_FreeSurface(surface);
        return nullptr;
    }
    surface->w = width;
    surface->h = height;
    //surface->pitch = SDL_CalculatePitch(format, width);
    SDL_SetClipRect(surface, nullptr);

    //if (SDL_ISPIXELFORMAT_INDEXED(surface->format)) {
        SDL_Palette *palette =
            SDL_AllocPalette((1 << surface->format->BitsPerPixel));
        if (!palette) {
            SDL_FreeSurface(surface);
            return nullptr;
        }
        if (palette->ncolors == 2) {
            /* Create a black and white bitmap palette */
            palette->colors[0].r = 0xFF;
            palette->colors[0].g = 0xFF;
            palette->colors[0].b = 0xFF;
            palette->colors[1].r = 0x00;
            palette->colors[1].g = 0x00;
            palette->colors[1].b = 0x00;
        }
        SDL_SetSurfacePalette(surface, palette);
        SDL_FreePalette(palette);
    //}

    /* Get the pixels */
    if (surface->w && surface->h) {
        /* Assumptions checked in surface_size_assumptions assert above */
        Sint64 size = ((Sint64)surface->h * surface->pitch);
        if (size < 0 || size > SDL_MAX_SINT32) {
            /* Overflow... */
            SDL_FreeSurface(surface);
            SDL_OutOfMemory();
            return NULL;
        }

        surface->pixels = SDL_malloc((size_t)size);
        if (!surface->pixels) {
            SDL_FreeSurface(surface);
            SDL_OutOfMemory();
            return NULL;
        }
        /* This is important for bitmaps */
        SDL_memset(surface->pixels, 0, surface->h * surface->pitch);
    }

    /* Allocate an empty mapping
    surface->map = SDL_AllocBlitMap();
    if (!surface->map) {
        SDL_FreeSurface(surface);
        return NULL;
    }
    */
    /* By default surface with an alpha mask are set up for blending */
    if (surface->format->Amask) {
        //SDL_SetSurfaceBlendMode(surface, SDL_BLENDMODE_BLEND);  //arczi
    }

    /* The surface is ready to go */
    surface->refcount = 1;
    return surface;
}
	
char* SDL_GetPrefPath(const char* org, const char* app) { return (char*)org; }

char* SDL_GetBasePath(void) {
    char buffer [100];
    sprintf(buffer,"envarc:devilution/");

    return buffer;
}

char* SDL_GetClipboardText(void)
{
    return "";
}


#ifdef __cplusplus
}
#endif