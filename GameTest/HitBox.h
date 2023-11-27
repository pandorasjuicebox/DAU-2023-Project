//-----------------------------------------------------------------------------
// HitBox.h
// Header file for the HitBox class.
//-----------------------------------------------------------------------------

class HitBox {
public:
	bool Collides(HitBox hitBox);
	float GetBoxLeft();
	float GetBoxHeight();
	void SetBoxTop(float &boxTop);
	void SetBoxLeft(float &boxLeft);
	void SetBoxBottom(float &boxBottom);
	void SetBoxRight(float &boxRight);
	void SetBoxHeight(float &height);

private: 
	float* boxTop;
	float* boxLeft;
	float* boxBottom;
	float* boxRight;
	float* boxHeight;
};