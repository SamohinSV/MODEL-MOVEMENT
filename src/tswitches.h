#ifndef TSWITCHES_H
#define TSWITCHES_H


class TSwitches
{
public:
    TSwitches();


    void AdvanceSwitch_F();
    void FallBackSwitch_F();

    bool CheckSign();
    bool CheckAccuracy();
    void SetAccuracy(float Accur);
    float  GetE();
private:
  float Switch_F[2];

  float Accuracy;
  bool Enabled;
  bool Happened;
  float AppearTime;
};

#endif // TSWITCHES_H
