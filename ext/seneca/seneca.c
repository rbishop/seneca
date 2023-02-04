#include "seneca.h"

VALUE rb_mSeneca;

void
Init_seneca(void)
{
  rb_mSeneca = rb_define_module("Seneca");
}
