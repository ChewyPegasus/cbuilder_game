object Form2: TForm2
  Left = 549
  Top = 305
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
  ClientHeight = 187
  ClientWidth = 351
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 329
    Height = 65
    Caption = #1056#1072#1079#1084#1077#1088#1099' '#1087#1086#1083#1103
    TabOrder = 0
    VerticalAlignment = taAlignTop
    object Label1: TLabel
      Left = 16
      Top = 13
      Width = 121
      Height = 13
      AutoSize = False
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1090#1088#1086#1082
    end
    object Label2: TLabel
      Left = 208
      Top = 13
      Width = 121
      Height = 13
      AutoSize = False
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1090#1086#1083#1073#1094#1086#1074
    end
    object SpinEdit1: TSpinEdit
      Left = 8
      Top = 32
      Width = 121
      Height = 22
      MaxValue = 50
      MinValue = 10
      TabOrder = 0
      Value = 50
    end
    object SpinEdit2: TSpinEdit
      Left = 200
      Top = 32
      Width = 121
      Height = 22
      MaxValue = 50
      MinValue = 10
      TabOrder = 1
      Value = 50
    end
  end
  object Panel2: TPanel
    Left = 8
    Top = 79
    Width = 329
    Height = 65
    Caption = #1043#1088#1072#1085#1080#1094#1099' '#1088#1072#1085#1076#1086#1084#1072
    TabOrder = 1
    VerticalAlignment = taAlignTop
    object Label3: TLabel
      Left = 32
      Top = 13
      Width = 97
      Height = 13
      AutoSize = False
      Caption = #1052#1080#1085#1080#1084#1091#1084
    end
    object Label4: TLabel
      Left = 224
      Top = 13
      Width = 97
      Height = 13
      AutoSize = False
      Caption = #1052#1072#1082#1089#1080#1084#1091#1084
    end
    object SpinEdit3: TSpinEdit
      Left = 8
      Top = 32
      Width = 121
      Height = 22
      MaxValue = 10
      MinValue = 1
      TabOrder = 0
      Value = 1
    end
    object SpinEdit4: TSpinEdit
      Left = 200
      Top = 32
      Width = 121
      Height = 22
      MaxValue = 10
      MinValue = 1
      TabOrder = 1
      Value = 6
    end
  end
  object BitBtn1: TBitBtn
    Left = 8
    Top = 150
    Width = 329
    Height = 25
    Caption = #1055#1086#1076#1090#1074#1077#1088#1076#1080#1090#1100' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
    Kind = bkOK
    NumGlyphs = 2
    TabOrder = 2
    OnClick = BitBtn1Click
  end
end
