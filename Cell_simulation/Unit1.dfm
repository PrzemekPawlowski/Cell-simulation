object Form1: TForm1
  Left = 394
  Top = 108
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Life'
  ClientHeight = 486
  ClientWidth = 866
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PerformanceGraph1: TPerformanceGraph
    Left = 640
    Top = 8
    Width = 209
    Height = 441
    Align = alCustom
    Kind = pgBar
    ParentShowHint = False
    StepSize = 2
    Gradient = 50
    ShowHint = True
  end
  object Label1: TLabel
    Left = 224
    Top = 464
    Width = 17
    Height = 17
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object DrawGrid: TDrawGrid
    Left = 0
    Top = 8
    Width = 625
    Height = 449
    Cursor = crHandPoint
    HelpContext = 1
    Align = alCustom
    BiDiMode = bdLeftToRight
    Color = clBtnFace
    ColCount = 40
    Ctl3D = True
    DefaultColWidth = 10
    DefaultRowHeight = 10
    DragCursor = crHelp
    FixedCols = 0
    RowCount = 40
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -3
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Options = [goVertLine, goHorzLine, goRangeSelect]
    ParentBiDiMode = False
    ParentCtl3D = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 0
    OnDrawCell = DrawGridDrawCell
    RowHeights = (
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10
      10)
  end
  object Button1: TButton
    Left = 448
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Start/Stop'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 448
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Losuj'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 448
    Top = 96
    Width = 121
    Height = 21
    TabOrder = 3
    Text = '150'
  end
  object StaticText1: TStaticText
    Left = 448
    Top = 72
    Width = 99
    Height = 17
    Caption = 'Podaj ilo'#347#263' kom'#243'rek'
    TabOrder = 4
  end
  object CheckBox1: TCheckBox
    Left = 528
    Top = 16
    Width = 49
    Height = 17
    Color = clInactiveBorder
    ParentColor = False
    TabOrder = 5
  end
  object StaticText2: TStaticText
    Left = 664
    Top = 456
    Width = 108
    Height = 17
    Caption = 'Ilo'#347#263' '#380'ywych kom'#243'rek'
    TabOrder = 6
  end
  object Edit2: TEdit
    Left = 776
    Top = 456
    Width = 49
    Height = 21
    TabOrder = 7
  end
  object Button3: TButton
    Left = 536
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Reset'
    TabOrder = 8
    OnClick = Button3Click
  end
  object StaticText3: TStaticText
    Left = 448
    Top = 280
    Width = 94
    Height = 17
    Caption = 'Kom'#243'rka ginie gdy:'
    TabOrder = 9
  end
  object StaticText4: TStaticText
    Left = 448
    Top = 312
    Width = 62
    Height = 17
    Caption = 'Ma mniej ni'#380
    TabOrder = 10
  end
  object Edit3: TEdit
    Left = 520
    Top = 304
    Width = 41
    Height = 21
    MaxLength = 8
    TabOrder = 11
    Text = '2'
  end
  object StaticText5: TStaticText
    Left = 568
    Top = 312
    Width = 48
    Height = 17
    Caption = 's'#261'siad'#243'w'
    TabOrder = 12
  end
  object StaticText6: TStaticText
    Left = 448
    Top = 352
    Width = 68
    Height = 17
    Caption = 'Ma wi'#281'cej ni'#380
    TabOrder = 13
  end
  object Edit4: TEdit
    Left = 520
    Top = 344
    Width = 41
    Height = 21
    MaxLength = 8
    TabOrder = 14
    Text = '3'
  end
  object StaticText7: TStaticText
    Left = 568
    Top = 352
    Width = 48
    Height = 17
    Caption = 's'#261'siad'#243'w'
    TabOrder = 15
  end
  object StaticText8: TStaticText
    Left = 448
    Top = 384
    Width = 102
    Height = 17
    Caption = 'Kom'#243'rka o'#380'ywa gdy:'
    TabOrder = 16
  end
  object StaticText9: TStaticText
    Left = 448
    Top = 416
    Width = 70
    Height = 17
    Caption = 'Ma dok'#322'adnie'
    TabOrder = 17
  end
  object Edit5: TEdit
    Left = 520
    Top = 408
    Width = 41
    Height = 21
    MaxLength = 8
    TabOrder = 18
    Text = '3'
  end
  object StaticText11: TStaticText
    Left = 568
    Top = 416
    Width = 48
    Height = 17
    Caption = 's'#261'siad'#243'w'
    TabOrder = 19
  end
  object StaticText10: TStaticText
    Left = 448
    Top = 128
    Width = 94
    Height = 17
    Caption = 'Czas w sekundach'
    TabOrder = 20
  end
  object Edit6: TEdit
    Left = 448
    Top = 144
    Width = 65
    Height = 21
    TabOrder = 21
    Text = '0,1'
  end
  object StaticText12: TStaticText
    Left = 8
    Top = 464
    Width = 131
    Height = 17
    Caption = ' Przemys'#322'aw Paw'#322'owski '#169
    TabOrder = 22
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 568
  end
  object Timer2: TTimer
    Enabled = False
    OnTimer = Timer2Timer
    Left = 592
  end
end
