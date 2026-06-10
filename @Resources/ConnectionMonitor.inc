[MeasurePing]
Measure=Plugin
Plugin=PingPlugin
DestAddress=#ServerIP#
UpdateRate=5
Timeout=5000
TimeoutValue=-1

[MeasureShowGreen]
Measure=Calc
Formula=MeasurePing
IfCondition=(MeasureShowGreen > 0) && (MeasureShowGreen < #PingGreenMax#)
IfTrueAction=[!ShowMeter MeterGreen][!HideMeter MeterYellow][!HideMeter MeterRed][!Redraw]
IfFalseAction=[!HideMeter MeterGreen]

[MeasureShowYellow]
Measure=Calc
Formula=MeasurePing
IfCondition=(MeasureShowYellow >= #PingGreenMax#) && (MeasureShowYellow < #PingYellowMax#)
IfTrueAction=[!ShowMeter MeterYellow][!HideMeter MeterGreen][!HideMeter MeterRed][!Redraw]
IfFalseAction=[!HideMeter MeterYellow]

[MeasureShowRed]
Measure=Calc
Formula=MeasurePing
IfCondition=(MeasureShowRed < 0) || (MeasureShowRed >= #PingYellowMax#)
IfTrueAction=[!ShowMeter MeterRed][!HideMeter MeterGreen][!HideMeter MeterYellow][!Redraw]
IfFalseAction=[!HideMeter MeterRed]

[MeasurePingDisplay]
Measure=Calc
Formula=MeasurePing
IfCondition=(MeasurePingDisplay < 0) || (MeasurePingDisplay >= #PingYellowMax#)
IfTrueAction=[!SetOption MeterPingText Text "Offline"][!UpdateMeter MeterPingText][!Redraw]
IfFalseAction=[!SetOption MeterPingText Text "%1 ms"][!UpdateMeter MeterPingText][!Redraw]

[MeterBackground]
Meter=Shape
Shape=Rectangle 0,0,220,50,8 | Fill Color 0,0,0,100 | StrokeWidth 0

[MeterGreen]
Meter=Shape
Shape=Ellipse 25,25,8 | Fill Color 46,204,113,255 | StrokeWidth 0
Hidden=1

[MeterYellow]
Meter=Shape
Shape=Ellipse 25,25,8 | Fill Color 241,196,15,255 | StrokeWidth 0
Hidden=1

[MeterRed]
Meter=Shape
Shape=Ellipse 25,25,8 | Fill Color 231,76,60,255 | StrokeWidth 0
Hidden=1

[MeterServerName]
Meter=String
Text=#ServerName#
X=45
Y=10
FontColor=255,255,255,255
FontFace=Segoe UI
FontSize=11
FontWeight=700
AntiAlias=1

[MeterPingText]
Meter=String
MeasureName=MeasurePing
NumOfDecimals=0
X=45
Y=28
FontColor=200,200,200,255
FontFace=Segoe UI
FontSize=9
Text="%1 ms"
DynamicVariables=1
AntiAlias=1
