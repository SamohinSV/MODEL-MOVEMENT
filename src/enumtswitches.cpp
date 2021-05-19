#include "enumtswitches.h"
#include <math.h>

EnumTSwitches::EnumTSwitches()
{  
    KeysBand.resize (Keys.size ());
}

void EnumTSwitches::CreateAccuracy(float accar)
{
    for (int i = 0; i < KeysBand.size (); i++) {
        KeysBand[i].SetAccuracy (accar);
    }
}

void EnumTSwitches::AdvanceSwitch_F()
{
    for(auto &n:KeysBand)
        n.AdvanceSwitch_F ();
}

void EnumTSwitches::FallBackSwitch_F()
{
    for(auto &n:KeysBand)
        n.FallBackSwitch_F();
}

void EnumTSwitches::CheckSwitches(QVector<int> &KeysSet)
{
    for (int i = 0; i < KeysBand.size (); i++) {
       if (KeysBand[i].CheckSign ())
          KeysSet.push_back (i);
    }
}

bool EnumTSwitches::CheckAccuracyN(int i)
{
    return  KeysBand[i].CheckAccuracy ();
}

float EnumTSwitches::getE(int i)
{
    return KeysBand[i].GetE();
}

int EnumTSwitches::length()
{
    return KeysBand.size ();
}
