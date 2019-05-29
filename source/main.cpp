#include <m3dia.hpp>

#include <citro2d.h>
#include <unistd.h>

#define SPRITE_SHEETS 1

static C2D_SpriteSheet spriteSheet[SPRITE_SHEETS];
int microsecond = 3*100000;

int main(){

  m3d::Applet app;

  gfxInitDefault();
  C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
  C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
  C2D_Prepare();

  C3D_RenderTarget* target;
  target = C2D_CreateScreenTarget(GFX_TOP   , GFX_LEFT);

  spriteSheet[0] = C2D_SpriteSheetLoad("romfs:/images.t3x");
  if (!spriteSheet[0]) svcBreak(USERBREAK_PANIC);
  C2D_Image Image1 = C2D_SpriteSheetGetImage(spriteSheet[0], 0);
  C2D_Image Image2 = C2D_SpriteSheetGetImage(spriteSheet[0], 1);
  
  m3d::Music music("romfs:/bgm.mp3");
  music.play();

 while (aptMainLoop()){
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_SceneBegin(target);
	C2D_TargetClear(target, C2D_Color32(0x00, 0x00, 0x00, 0xFF));
    C2D_DrawImageAt(Image1, 0.0f, 0.0f, 0.0f, NULL, 1.0f, 1.0f);
	usleep(microsecond);
	C3D_FrameEnd(0);

	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_SceneBegin(target);
	C2D_TargetClear(target, C2D_Color32(0x00, 0x00, 0x00, 0xFF));
	C2D_DrawImageAt(Image2, 0.0f, 0.0f, 0.0f, NULL, 1.0f, 1.0f);
	usleep(microsecond);
    C3D_FrameEnd(0);
  }
  return 0;
}