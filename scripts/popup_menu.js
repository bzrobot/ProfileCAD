function Popup_XformMenu()
{
  ClearPopupMenu();
  AppendPopupMenu("Scale", "XformScale();");
  AppendPopupMenu("Filter", "XformFilter();");
  AppendPopupMenu("Back", "Popup_MainMenu_Show();");
  ShowPopupMenu();
}
function Popup_ModifyMenu()
{
  ClearPopupMenu();
  AppendPopupMenu("Trim 1", "ModifyTrim1();");
  AppendPopupMenu("Trim 2", "ModifyTrim2();");
  AppendPopupMenu("Fillet", "ModifyFillet();");
  AppendPopupMenu("Back", "Popup_MainMenu_Show();");
  ShowPopupMenu();
}
function Popup_LineMenu()
{
  ClearPopupMenu();
  AppendPopupMenu("Vertical Origin", "DrawLineVerticalFromOrigin();");
  AppendPopupMenu("Horizontal Origin", "DrawLineHorizontalFromOrigin();");
  AppendPopupMenu("Vertical", "DrawLineVerticalFromEndPoint();");
  AppendPopupMenu("Horizontal", "DrawLineHorizontalFromEndPoint();");
  AppendPopupMenu("Endpoints", "DrawLineEndpoints();");
  AppendPopupMenu("Perpendicular", "DrawLinePerpendicular();");
  AppendPopupMenu("Parallel", "DrawLineParallel();");
  AppendPopupMenu("Back", "Popup_MainMenu_Show();");
  ShowPopupMenu();
}
function Popup_ArcMenu()
{
  ClearPopupMenu();
  AppendPopupMenu("Circle Radius", "DrawCircleRadius();");
  AppendPopupMenu("Circle Diameter", "DrawCircleDiameter();");
  AppendPopupMenu("Back", "Popup_MainMenu_Show();");
  ShowPopupMenu();
}
function Popup_ScreenMenu()
{
  ClearPopupMenu();
  AppendPopupMenu("Change Color", "ScreenChangeColor();");
  AppendPopupMenu("Back", "Popup_MainMenu_Show();");
  ShowPopupMenu();
}
function Popup_DimensionMenu()
{
  ClearPopupMenu();
  AppendPopupMenu("Point", "DimensionPoint();");
  AppendPopupMenu("Back", "Popup_MainMenu_Show();");
  ShowPopupMenu();
}
function Popup_MainMenu()
{
  ClearPopupMenu();
  AppendPopupMenu("Line", "Popup_LineMenu();");
  AppendPopupMenu("Arc", "Popup_ArcMenu();");
  AppendPopupMenu("Modify", "Popup_ModifyMenu();");
  AppendPopupMenu("Xform", "Popup_XformMenu();");
  AppendPopupMenu("Dimension", "Popup_DimensionMenu();");
  //AppendPopupMenu("Advanced", "Popup_AdvancedMenu();");
  AppendPopupMenu("Screen", "Popup_ScreenMenu();");
  AppendPopupMenu("Repaint", "Repaint();");
}
function Popup_MainMenu_Show() //Used with back
{
  Popup_MainMenu();
  ShowPopupMenu();
}
