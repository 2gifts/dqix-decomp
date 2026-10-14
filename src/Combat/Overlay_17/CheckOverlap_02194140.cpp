#include <globaldefs.h>
#include "World/Object3D.h"

// USA: func_ov017_02194140  (semantic: CheckOverlap_02194140)
extern "C" ARM int func_ov017_02194140(Object3D* self, Object3D* other) {
	int extSelf = self->GetHeight();
	int extOther = other->GetHeight();

	if (!(self->position_.y + extSelf >= other->position_.y &&
	      other->position_.y + extOther >= self->position_.y)) return 0;

	int half = (self->GetRadius() >> 1) + (other->GetRadius() >> 1);

	if (half < fix32abs(self->position_.x - other->position_.x) ||
	    half < fix32abs(self->position_.z - other->position_.z)) return 0;

	int d = Vector3fix_Distance(&self->position_, &other->position_);
	return half >= d;
}
