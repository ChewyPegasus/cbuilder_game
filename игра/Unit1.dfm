object Form1: TForm1
  Left = 360
  Top = 169
  Caption = #1062#1072#1088#1089#1090#1074#1072
  ClientHeight = 646
  ClientWidth = 803
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object DrawGrid1: TDrawGrid
    Left = 0
    Top = 0
    Width = 609
    Height = 611
    Cursor = crCross
    ColCount = 50
    DefaultColWidth = 10
    DefaultRowHeight = 10
    FixedCols = 0
    RowCount = 50
    FixedRows = 0
    GridLineWidth = 0
    TabOrder = 0
    OnDrawCell = DrawGrid1DrawCell
    OnMouseDown = DrawGrid1MouseDown
    OnMouseUp = DrawGrid1MouseUp
  end
  object Panel1: TPanel
    Left = 623
    Top = 8
    Width = 172
    Height = 289
    Caption = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    VerticalAlignment = taAlignTop
    object Edit1: TEdit
      Left = 8
      Top = 32
      Width = 57
      Height = 24
      Alignment = taRightJustify
      ReadOnly = True
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 104
      Top = 32
      Width = 57
      Height = 24
      ReadOnly = True
      TabOrder = 1
    end
    object Button1: TButton
      Left = 8
      Top = 62
      Width = 153
      Height = 25
      Caption = #1057#1075#1077#1085#1077#1088#1080#1088#1086#1074#1072#1090#1100
      TabOrder = 2
      OnClick = Button1Click
    end
    object BitBtn1: TBitBtn
      Left = 8
      Top = 133
      Width = 153
      Height = 41
      Caption = '&'#1054#1095#1080#1089#1090#1080#1090#1100' '#1087#1086#1083#1077
      Kind = bkRetry
      NumGlyphs = 2
      TabOrder = 3
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 8
      Top = 180
      Width = 153
      Height = 41
      Caption = #1050#1090#1086' '#1087#1086#1073#1077#1076#1080#1083
      Kind = bkHelp
      NumGlyphs = 2
      TabOrder = 4
      OnClick = BitBtn2Click
    end
    object BitBtn3: TBitBtn
      Left = 8
      Top = 93
      Width = 153
      Height = 34
      Caption = #1055#1088#1086#1087#1091#1089#1090#1080#1090#1100' '#1093#1086#1076
      Kind = bkNo
      NumGlyphs = 2
      TabOrder = 5
      OnClick = BitBtn3Click
    end
    object LabeledEdit1: TLabeledEdit
      Left = 8
      Top = 248
      Width = 161
      Height = 24
      Alignment = taCenter
      EditLabel.Width = 107
      EditLabel.Height = 16
      EditLabel.Caption = #1050#1090#1086' '#1089#1077#1081#1095#1072#1089' '#1093#1086#1076#1080#1090'?'
      ReadOnly = True
      TabOrder = 6
      Text = #1048#1075#1088#1086#1082'1'
    end
  end
  object MainMenu1: TMainMenu
    Left = 736
    Top = 424
    object N1: TMenuItem
      Caption = #1052#1077#1085#1102
      object N5: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080#1075#1088#1091
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1080#1075#1088#1091
        OnClick = N6Click
      end
    end
    object N2: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      object N3: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1080#1075#1088#1099
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1080#1075#1088#1086#1082#1086#1074
        OnClick = N4Click
      end
    end
  end
end
