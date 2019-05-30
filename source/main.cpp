#include <m3dia.hpp>

int main() {
	//set
    m3d::Applet app;
    m3d::Screen scr;
    m3d::Sprite spr;

	//image
    int Table[] = {0, 1, -1};
    spr.setSpriteSheet("romfs:/images.t3x");
    spr.Animate(Table, 250, true);
	
	//sound
	m3d::Music music("romfs:/bgm.mp3");
	music.loop(true);
	music.play();
	
	//main loop
    while (app.isRunning()) {
		if (m3d::buttons::buttonPressed(m3d::buttons::Button::Start)) app.exit();
        spr.updateSprites();
        scr.drawTop(spr);
        scr.render();
    }
}