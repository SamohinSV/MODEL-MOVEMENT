#include "tswitches.h"
#include "math.h"

TSwitches::TSwitches()
{

}

void TSwitches::AdvanceSwitch_F()
{
    Switch_F[1] = Switch_F[0];
}

void TSwitches::FallBackSwitch_F()
{
    Switch_F[0] = Switch_F[1];
}

bool TSwitches::CheckSign()
{
    if (Enabled) {
        if (signbit (Switch_F[0]) == signbit (Switch_F[1]))
            return true;
        else
            return false;
    } else
        return false;
}

bool TSwitches::CheckAccuracy()
{
    return (abs(Switch_F[0]) - Accuracy) <= pow (Accuracy,2);
}

void TSwitches::SetAccuracy(float Accur)
{
    Accuracy = Accur;
}

float TSwitches::GetE()
{
    if (abs(Switch_F[0])>Accuracy) {
        if (signbit (Switch_F[1]))
            return  Switch_F[1]/(Switch_F[1]-Switch_F[0]);
        else
            return Accuracy/abs(Switch_F[0]);
    } else
          return 1;
}

void TSwitches::SetKey(QString name)
{
    Key = name;
}
