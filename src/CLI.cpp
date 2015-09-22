#include <CLI.h>

using namespace std;

struct sub_sub_menu_item_t{
  string c; //keystroke
  string msg;
  void *(*cmd)();
};

struct sub_menu_item_t{
  string c; //keystroke
  string msg;
  sub_sub_menu_item_t submenu[10];
};

struct menu_item_t{
  string c; //keystroke
  string msg;
  sub_menu_item_t submenu[10];
};

void *(*textCallback)();
color_t CurrentColor = GREEN;
std::string CurrentFile;
int Level = 0;
int Level1Selection;
int Level2Selection;
bool TextInput = false;
bool TextReady = false;
string text = "";

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

#define CLI_MENU_ITEM_SEPERATOR "   "
#define CLI_MENU_ITEM_LINK  " - "

std::string cliGetCurrentFile()
{
  return CurrentFile;
}
float cliGetInput()
{
  if (text.size() == 0)
  {
    return 0;
  }
  text.replace(text.find("> "), sizeof("> ")-1, "");
  float input;
  if (text.find("*") != std::string::npos) //Evaluate multiplication
  {
    std::vector<std::string> factors = split(text, '*');
    input = 0;
    if (factors.size() > 1)
    {
      input = atof(factors[0].c_str()) * atof(factors[1].c_str());
    }
    //printf("(cliGetInput) Mult Eval: %.6f\n", input);
  }
  else if(text.find("/") != std::string::npos) //Evaluate division
  {
    std::vector<std::string> factors = split(text, '/');
    input = 0;
    if (factors.size() > 1)
    {
      input = atof(factors[0].c_str()) / atof(factors[1].c_str());
    }
    //printf("(cliGetInput) Div Eval: %.6f\n", input);
  }
  else
  {
    input = (float)atof(text.c_str());
  }
  if (!isnan(input))
  {
    return input;
  }
  else
  {
    return 0;
  }
}
std::string cliGetTextInput()
{
  if (text.size() == 0)
  {
    return "";
  }
  text.replace(text.find("> "), sizeof("> ")-1, "");
  return text;
}
void *cliCreateLineEndpoints()
{
  std::vector<cadEntity> e = cadGetSelected();
  if (e.size() < 2)
  {
    return NULL;
  }
  point_t Start = e[0].SelectedAt;
  point_t End = e[1].SelectedAt;
  cadSetColor(CurrentColor);
  cadDrawLine(Start, End);
  cliScreenUnSelectAll();
  return NULL;
}
void *cliCreateLineVerticalEndpoint()
{
  if (TextReady == true)
  {
    TextReady = false;
    float input = cliGetInput();
    std::vector<cadEntity> e = cadGetSelected();
    if (e.size() < 1)
    {
      return NULL;
    }
    point_t Start = e[0].SelectedAt;
    point_t End = { e[0].SelectedAt.x , input };
    cadSetColor(CurrentColor);
    cadDrawLine(Start, End);
    cliScreenUnSelectAll();
    return NULL;
  }
  textCallback = &cliCreateLineVerticalEndpoint;
  TextInput = true;
  cliPush("> ");
  uiEdit(0, uiEntity{UI_TEXT, RED, "Input Y endpoint!", UI_MENU_POSITION});
  return NULL;
}
void *cliCreateLineHorizontalEndpoint()
{
  if (TextReady == true)
  {
    TextReady = false;
    float input = cliGetInput();
    std::vector<cadEntity> e = cadGetSelected();
    if (e.size() < 1)
    {
      return NULL;
    }
    point_t Start = e[0].SelectedAt;
    point_t End = { (float)atof(text.c_str()), e[0].SelectedAt.y };
    cadSetColor(CurrentColor);
    cadDrawLine(Start, End);
    cliScreenUnSelectAll();
    return NULL;
  }
  textCallback = &cliCreateLineHorizontalEndpoint;
  TextInput = true;
  cliPush("> ");
  uiEdit(0, uiEntity{UI_TEXT, RED, "Input X endpoint!", UI_MENU_POSITION});
  return NULL;
}
void *cliCreateLineVerticalOrigin()
{
    if (TextReady == true)
    {
      TextReady = false;
      float input = cliGetInput();
      point_t Start = { 0, 0};
      point_t End = { 0 , input };
      cadSetColor(CurrentColor);
      cadDrawLine(Start, End);
      return NULL;
    }
    textCallback = &cliCreateLineVerticalOrigin;
    TextInput = true;
    cliPush("> ");
    uiEdit(0, uiEntity{UI_TEXT, RED, "Input Y coordinant!", UI_MENU_POSITION});
    return NULL;
}
void *cliCreateLineHorizontalOrigin()
{
  if (TextReady == true)
  {
    TextReady = false;
    float input = cliGetInput();
    point_t Start = { 0, 0};
    point_t End = {input, 0};
    cadSetColor(CurrentColor);
    cadDrawLine(Start, End);
    return NULL;
  }
  textCallback = &cliCreateLineHorizontalOrigin;
  TextInput = true;
  cliPush("> ");
  uiEdit(0, uiEntity{UI_TEXT, RED, "Input X coordinant!", UI_MENU_POSITION});
  return NULL;
}
void *cliCreateLinePerpendicular()
{
  if (TextReady == true)
  {
    TextReady = false;
    float input = cliGetInput();
    std::vector<cadEntity> e = cadGetSelected();
    if (e.size() == 1) //Make sure we have only one entity seleced
    {
      line_t p = geoGetPerpendicularLine(line_t{ e[0].Line.start,  e[0].Line.end}, mouseCadLastClickPos(), input);
      point_t Start = p.start;
      point_t End = p.end;
      cadSetColor(CurrentColor);
      cadDrawLine(Start, End);
      cliScreenUnSelectAll();
      return NULL;
    }
    return NULL;
  }
  textCallback = &cliCreateLinePerpendicular;
  TextInput = true;
  cliPush("> ");
  uiEdit(3, uiEntity{UI_TEXT, RED, "Click to indecated offset direction!", UI_HINT_POSITION});
  uiEdit(0, uiEntity{UI_TEXT, RED, "Input distance!", UI_MENU_POSITION});
  return NULL;
}
void *cliCreateLineParallel()
{
  if (TextReady == true)
  {
    TextReady = false;
    float input = cliGetInput();
    std::vector<cadEntity> e = cadGetSelected();
    if (e.size() == 1) //Make sure we have only one entity seleced
    {
      //V printf("(cliCreateLinePerpendicular) %d Entitys selected!\n", e.size());
      line_t p = geoGetParallelLine(line_t{ e[0].Line.start,  e[0].Line.end}, mouseCadLastClickPos(), input);
      point_t Start = p.start;
      point_t End = p.end;
      cadSetColor(CurrentColor);
      cadDrawLine(Start, End);
      cliScreenUnSelectAll();
      return NULL;
    }
    return NULL;
  }
  textCallback = &cliCreateLineParallel;
  TextInput = true;
  cliPush("> ");
  uiEdit(0, uiEntity{UI_TEXT, RED, "Input distance!", UI_MENU_POSITION});
  uiEdit(3, uiEntity{UI_TEXT, RED, "Click to indecated offset direction!", UI_HINT_POSITION});
  return NULL;
}
void *cliCreateCircleCenterDiameter()
{
  if (TextReady == true)
  {
    TextReady = false;
    float input = cliGetInput();
    std::vector<cadEntity> e = cadGetSelected();
    if (e.size() == 1) //Make sure we have only one entity seleced
    {
      point_t center = mouseCadLastSnapClick();
      float radius = input / 2;
      point_t endpoints = point_t{ center.x + radius, center.y };
      cadSetColor(CurrentColor);
      cadDrawArc(arc_t{ endpoints, endpoints, center, radius, ARC_CW });
      cliScreenUnSelectAll();
      return NULL;
    }
    return NULL;
  }
  textCallback = &cliCreateCircleCenterDiameter;
  TextInput = true;
  cliPush("> ");
  uiEdit(0, uiEntity{UI_TEXT, RED, "Circle Diameter?", UI_MENU_POSITION});
  uiEdit(3, uiEntity{UI_TEXT, RED, "Click for center point!", UI_HINT_POSITION});
  return NULL;
}
void *cliCreateCircleCenterRadius()
{
  if (TextReady == true)
  {
    TextReady = false;
    float input = cliGetInput();
    std::vector<cadEntity> e = cadGetSelected();
    if (e.size() == 1) //Make sure we have only one entity seleced
    {
      point_t center = mouseCadLastSnapClick();
      float radius = input;
      point_t endpoints = point_t{ center.x + radius, center.y };
      cadSetColor(CurrentColor);
      cadDrawArc(arc_t{ endpoints, endpoints, center, radius, ARC_CW });
      cliScreenUnSelectAll();
      return NULL;
    }
    return NULL;
  }
  textCallback = &cliCreateCircleCenterRadius;
  TextInput = true;
  cliPush("> ");
  uiEdit(0, uiEntity{UI_TEXT, RED, "Circle Radius?", UI_MENU_POSITION});
  uiEdit(3, uiEntity{UI_TEXT, RED, "Click for center point!", UI_HINT_POSITION});
  return NULL;
}
void *cliCreateCircleTwoPoints()
{
  //
}
void *cliScreenSelectAll()
{
  int m = cadGetEntityArrayIndex();
  cadEntity e;
  for (int a = 0; a < m; a++)
  {
    e = cadGetEntityArray(a);
    e.Selected = true;
    cadEdit(a, e);
  }
}
void *cliScreenUnSelectAll()
{
  int m = cadGetEntityArrayIndex();
  cadEntity e;
  for (int a = 0; a < m; a++)
  {
    e = cadGetEntityArray(a);
    e.Selected = false;
    cadEdit(a, e);
  }
}
void *cliScreenDeleteSelected()
{
  cadRemoveSelected();
}
void *cliViewPlaneXY() { sceneSetViewAngle(0, 0, 0); return NULL; }
void *cliViewPlaneYZ() { sceneSetViewAngle(0, 90, 0); return NULL; }
void *cliViewPlaneZX() { sceneSetViewAngle(90, 0, 0); return NULL; }
void *cliViewPlaneOrtho() { sceneSetViewAngle(45, 45, 45); return NULL; }
void *cliFileExit() { EXIT; return NULL; };
void *cliFileGetNew()
{
  if (TextReady == true)
  {
    TextReady = false;
    cliScreenSelectAll();
    cliScreenDeleteSelected();
    CurrentFile = cliGetTextInput();
    int r = fileOpen(CurrentFile);
    glutSetWindowTitle(CurrentFile.c_str());
    if (r == FILE_OPEN_ERROR) uiEdit(0, uiEntity{UI_TEXT, RED, "Error reading file!", UI_MENU_POSITION});
    if (r == FILE_UNKNOWN_FORMAT) uiEdit(0, uiEntity{UI_TEXT, RED, "Unknown file format!", UI_MENU_POSITION});
    return NULL;
  }
  textCallback = &cliFileGetNew;
  TextInput = true;
  cliPush("> ");
  uiEdit(0, uiEntity{UI_TEXT, RED, "Get File?", UI_MENU_POSITION});
  return NULL;
}
void *cliFileGetMerge()
{
  if (TextReady == true)
  {
    TextReady = false;
    CurrentFile = cliGetTextInput();
    glutSetWindowTitle(CurrentFile.c_str());
    int r = fileOpen(CurrentFile);
    if (r == FILE_OPEN_ERROR) uiEdit(0, uiEntity{UI_TEXT, RED, "Error reading file!", UI_MENU_POSITION});
    if (r == FILE_UNKNOWN_FORMAT) uiEdit(0, uiEntity{UI_TEXT, RED, "Unknown file format!", UI_MENU_POSITION});
    return NULL;
  }
  textCallback = &cliFileGetMerge;
  TextInput = true;
  cliPush("> ");
  uiEdit(0, uiEntity{UI_TEXT, RED, "Merge File?", UI_MENU_POSITION});
  return NULL;
}
void *cliFilePutNew()
{
  if (TextReady == true)
  {
    TextReady = false;
    CurrentFile = cliGetTextInput();
    int r = fileSave(CurrentFile);
    if (r == FILE_OPEN_ERROR) uiEdit(0, uiEntity{UI_TEXT, RED, "Error writing file!", UI_MENU_POSITION});
    return NULL;
  }
  textCallback = &cliFilePutNew;
  TextInput = true;
  cliPush("> ");
  uiEdit(0, uiEntity{UI_TEXT, RED, "New File Name?", UI_MENU_POSITION});
  return NULL;
}
void *cliFilePutCurrent()
{
  int r = fileSave(CurrentFile);
  if (r == FILE_OPEN_ERROR)
  {
    uiEdit(0, uiEntity{UI_TEXT, RED, "Error writing file!", UI_MENU_POSITION});
  }
  else
  {
    string t = "Saving " + CurrentFile;
    uiEdit(0, uiEntity{UI_TEXT, RED, t, UI_MENU_POSITION});
  }

}
void *cliScreenColorRed()
{
  CurrentColor = RED;
  cadEntity e;
  for (int x=0; x < cadGetEntityArrayIndex(); x++)
  {
    e = cadGetEntityArray(x);
    if (e.Selected && !e.Removed)
    {
      e.Color = CurrentColor;
      cadEdit(x, e);
    }
  }
  cliScreenUnSelectAll();
  return NULL;
}
void *cliScreenColorBlue()
{
  CurrentColor = BLUE;
  cadEntity e;
  for (int x=0; x < cadGetEntityArrayIndex(); x++)
  {
    e = cadGetEntityArray(x);
    if (e.Selected && !e.Removed)
    {
      e.Color = CurrentColor;
      cadEdit(x, e);
    }
  }
  cliScreenUnSelectAll();
  return NULL;
}
void *cliScreenColorGreen()
{
  CurrentColor = GREEN;
  cadEntity e;
  for (int x=0; x < cadGetEntityArrayIndex(); x++)
  {
    e = cadGetEntityArray(x);
    if (e.Selected && !e.Removed)
    {
      e.Color = CurrentColor;
      cadEdit(x, e);
    }
  }
  cliScreenUnSelectAll();
  return NULL;
}
void *cliScreenColorWhite()
{
  CurrentColor = WHITE;
  cadEntity e;
  for (int x=0; x < cadGetEntityArrayIndex(); x++)
  {
    e = cadGetEntityArray(x);
    if (e.Selected && !e.Removed)
    {
      e.Color = CurrentColor;
      cadEdit(x, e);
    }
  }
  cliScreenUnSelectAll();
  return NULL;
}
void *cliScreenColorBlack()
{
  CurrentColor = BLACK;
  cadEntity e;
  for (int x=0; x < cadGetEntityArrayIndex(); x++)
  {
    e = cadGetEntityArray(x);
    if (e.Selected && !e.Removed)
    {
      e.Color = CurrentColor;
      cadEdit(x, e);
    }
  }
  cliScreenUnSelectAll();
  return NULL;
}
void *cliScreenColorYellow()
{
  CurrentColor = YELLOW;
  cadEntity e;
  for (int x=0; x < cadGetEntityArrayIndex(); x++)
  {
    e = cadGetEntityArray(x);
    if (e.Selected && !e.Removed)
    {
      e.Color = CurrentColor;
      cadEdit(x, e);
    }
  }
  cliScreenUnSelectAll();
  return NULL;
}
void *cliScreenColorCyan()
{
  CurrentColor = CYAN;
  cadEntity e;
  for (int x=0; x < cadGetEntityArrayIndex(); x++)
  {
    e = cadGetEntityArray(x);
    if (e.Selected && !e.Removed)
    {
      e.Color = CurrentColor;
      cadEdit(x, e);
    }
  }
  cliScreenUnSelectAll();
  return NULL;
}
void *cliScreenColorMagenta()
{
  CurrentColor = MAGENTA;
  cadEntity e;
  for (int x=0; x < cadGetEntityArrayIndex(); x++)
  {
    e = cadGetEntityArray(x);
    if (e.Selected && !e.Removed)
    {
      e.Color = CurrentColor;
      cadEdit(x, e);
    }
  }
  cliScreenUnSelectAll();
  return NULL;
}
void *cliScreenColorGrey()
{
  CurrentColor = DARKGREY;
  cadEntity e;
  for (int x=0; x < cadGetEntityArrayIndex(); x++)
  {
    e = cadGetEntityArray(x);
    if (e.Selected && !e.Removed)
    {
      e.Color = CurrentColor;
      cadEdit(x, e);
    }
  }
  cliScreenUnSelectAll();
  return NULL;
}
void *cliScreenAnalyzeEntity()
{
  string t = "";
  cadEntity e;
  if (TextReady == true)
  {
    cliGetTextInput();
    TextReady = false;
    return NULL;
  }
  for (int x=0; x < cadGetEntityArrayIndex(); x++)
  {
    e = cadGetEntityArray(x);
    if (e.Selected && !e.Removed)
    {
      if (e.Type == CAD_ARC)
      {
        string direction;
        if (e.Arc.direction == ARC_CW)
        {
          direction = "CW";
        }
        else
        {
          direction = "CCW";
        }
        t.append("Type=> Arc, Direction=> " + direction + ", Diameter=> " + to_string(e.Arc.radius *2)
        + ", Radius=> " + to_string(e.Arc.radius)
        + ", Start Angle=> " + to_string(geoRadiansToDegrees(geoGetArcStartAngle(e.Arc)))
        + ", End Angle=> " + to_string(geoRadiansToDegrees(geoGetArcEndAngle(e.Arc)))
        + ", Length=> " + to_string(geoGetArcLength(e.Arc))
        );
      }
      if (e.Type == CAD_LINE)
      {
        t.append("Type=> Line, Length=> " + to_string(geoGetLineLength(e.Line))
        + ", Angle=> " + to_string(geoRadiansToDegrees(geoGetLineAngle(e.Line)))
        + ", Midpoint=> (" + to_string(geoGetLineMidpoint(e.Line).x) + ", " + to_string(geoGetLineMidpoint(e.Line).y) + ", " + to_string(geoGetLineMidpoint(e.Line).z) + ")"
        );
      }
    }
  }
  textCallback = &cliScreenAnalyzeEntity;
  TextInput = true;
  uiEdit(0, uiEntity{UI_TEXT, GREEN, t, UI_MENU_POSITION});
  return NULL;
}
void *cliXformTrim1()
{
  int index;
  std::vector<cadEntity> e = cadGetSelected();
  if (e.size() < 2)
  {
    return NULL;
  }
  point_t new_endpoint = geoGetIntersection(line_t{e[0].Line.start, e[0].Line.end}, line_t{e[1].Line.start, e[1].Line.end});
  V cout << KRED << "(cliXformTrim1) Intersection = ";
  V debugDumpPointStructure(new_endpoint);
  if (isnan(new_endpoint.x) || isnan(new_endpoint.y) || isnan(new_endpoint.z))
  {
    V cout << KRED << "(cliXformTrim1) No Intersection!" << KNORMAL << endl;
    return NULL;
  }
  //V printf("(cliXformTrim1) Intersection point is (%.6f, %.6f)\n", new_endpoint.x, new_endpoint.y);

  //Find which end of first selected line is closest to the Intersection point, then replace with intersection point
  float start_d = geoGetLineLength(line_t{ e[0].Line.start, new_endpoint });
  float end_d = geoGetLineLength(line_t{ e[0].Line.end, new_endpoint });
  //Doesnt work because were looking at first in array not first clicked
  //V printf("e[0].SelectionIndex = %d\ne[1].SelectionIndex = %d\n", e[0].SelectionIndex, e[1].SelectionIndex);
  if (start_d < end_d)
  {
      e[0].Line.start = new_endpoint;
  }
  else
  {
    e[0].Line.end = new_endpoint;
  }
  cadEdit(e[0].Index, e[0]);
  cliScreenUnSelectAll();
  return NULL;
}
void *cliXformTrim2()
{

}
void *cliXformTrimCircle()
{
  if (TextReady == true)
  {
    TextReady = false;
    //uiEdit(3, uiEntity{UI_TEXT, RED, "Click for center point!", UI_HINT_POSITION});
    cliGetTextInput();
    int index;
    std::vector<cadEntity> e = cadGetSelected();
    if (e.empty())
    {
      return NULL;
    }
    if (e.size() == 3)
    {
      if (e[0].Type == CAD_ARC && e[0].Line.start == e[0].Line.end && e[1].Type == CAD_LINE && e[2].Type == CAD_LINE) //Make sure first selection is a circle and second and third selections are lines
      {
        //printf("Line1 - X: %.6f, Y: %.6f\n", e[1].SelectedAt.x, e[1].SelectedAt.y);
        //printf("Line2 - X: %.6f, Y: %.6f\n", e[2].SelectedAt.x, e[2].SelectedAt.y);
        float d1 = geoGetLineLength(line_t{e[0].Arc.start, e[1].SelectedAt});
        float d2 = geoGetLineLength(line_t{e[0].Arc.end, e[1].SelectedAt});
        if (d1 < d2)
        {
          e[0].Arc.start = e[1].SelectedAt;
          e[0].Arc.end = e[2].SelectedAt;
        }
        else
        {
          e[0].Arc.end = e[1].SelectedAt;
          e[0].Arc.start = e[2].SelectedAt;
        }
        bool closest = false;
        std::vector<point_t> p = geoGetPointsOfArc(e[0].Arc);
        for (int z = 0; z < p.size(); z++)
        {
          if (geoInTolerance(p[z].x, e[0].SelectedAt.x, 0.050) && geoInTolerance(p[z].y, e[0].SelectedAt.y, 0.050))
          {
            closest = true;
          }
        }
        if (!closest)
        {
          e[0].Arc.direction = !e[0].Arc.direction;
        }
        cadEdit(e[0].Index, e[0]);
        cliScreenUnSelectAll();
      }
      else
      {
        //printf("Selection wasnt satisfied!\n");
      }
      return NULL;
    }
    return NULL;
  }
  textCallback = &cliXformTrimCircle;
  TextInput = true;
  cliPush("> ");
  uiEdit(3, uiEntity{UI_TEXT, RED, "Select Circle and two line endpoints and press enter!", UI_HINT_POSITION});
  return NULL;
}
void *cliXformFilletRadius()
{
  if (TextReady == true)
  {
    TextReady = false;
    arc_t fillet;
    fillet.radius = cliGetInput();
    std::vector<cadEntity> e = cadGetSelected();
    if (e.empty())
    {
      return NULL;
    }
    if (e.size() == 2) //Make sure we have two selections
    {
      if (e[0].Type == CAD_LINE && e[1].Type == CAD_LINE) //Make sure both selections are lines
      {
        point_t relative_center = geoGetLineMidpoint(line_t{point_t{e[0].SelectedAt}, point_t{e[1].SelectedAt}});
        V cout << KRED << "(cliXformFilletRadius) Relative Center = ";
        V debugDumpPointStructure(relative_center);
        line_t p_line_zero = geoGetParallelLine(e[0].Line, relative_center, fillet.radius);
        //cadDrawLine(p_line_zero);
        line_t p_line_one = geoGetParallelLine(e[1].Line, relative_center, fillet.radius);
        //cadDrawLine(p_line_one);
        //Get intersection point of both lines to get fillet arc center point
        fillet.center = geoGetLineIntersection(p_line_zero, p_line_one);
        V cout << KRED << "(cliXformFilletRadius) Arc Center = ";
        V debugDumpPointStructure(fillet.center);

        //Draw circle and find where each line intersects with circle and replace line and circle end points to create fillet
        fillet.start = point_t{fillet.center.x + fillet.radius, fillet.center.y};
        fillet.end = point_t{fillet.center.x + fillet.radius, fillet.center.y};
        point_t fillet_start = geoGetIntersection(e[0].Line, fillet);
        point_t fillet_end = geoGetIntersection(e[1].Line, fillet);
        fillet.start = fillet_start;
        fillet.end = fillet_end;

        //Determine direction of fillet by drawing a line from center to start and end point, if included angle is positive were CW
        float start_angle = geoGetLineAngle(line_t{fillet.center, fillet.start});
        float end_angle = geoGetLineAngle(line_t{fillet.center, fillet.end});
        V cout << KRED << "(cliXformFilletRadius) Arc Start Angle = " << start_angle << KNORMAL << endl;
        V cout << KRED << "(cliXformFilletRadius) Arc End Angle = " << end_angle << KNORMAL << endl;
        if ((start_angle - end_angle) > 0)
        {
          fillet.direction = ARC_CW;
          V cout << KRED << "(cliXformFilletRadius)\t Arc is CW" << KNORMAL << endl;
        }
        else
        {
          fillet.direction = ARC_CCW;
          V cout << KRED << "(cliXformFilletRadius)\t Arc is CCW" << KNORMAL << endl;
        }
        //Figure out which end of line 0 is closest to fillet start
        if (geoGetLineLength(line_t{ e[0].Line.start, fillet.start }) < geoGetLineLength(line_t{ e[0].Line.end, fillet.start }))
        {
          e[0].Line.start = fillet_start;
        }
        else
        {
          e[0].Line.start = fillet_end;
        }
        //Figure out which end of line 1 is closest to fillet end
        point_t line_one_endpoint;
        if (geoGetLineLength(line_t{ e[1].Line.start, fillet.end }) < geoGetLineLength(line_t{ e[1].Line.end, fillet.end }))
        {
          e[1].Line.start = fillet.end;
        }
        else
        {
          e[1].Line.start = fillet.end;
        }
        cadEdit(e[0].Index, e[0]); //Edit line 0
        cadEdit(e[1].Index, e[1]); //Edit line 1
        cadDrawArc(fillet); //Draw arc
        cliScreenUnSelectAll();
      }
    }
    return NULL;
  }
  textCallback = &cliXformFilletRadius;
  TextInput = true;
  cliPush("> ");
  uiEdit(0, uiEntity{UI_TEXT, RED, "Radius?", UI_MENU_POSITION});
  return NULL;
}

#define CLI_MENU_ITEMS 6
menu_item_t menu[CLI_MENU_ITEMS] = {
  { "f", "file",
    sub_menu_item_t{ "e", "exit",
         sub_sub_menu_item_t{ "y", "are you sure?", &cliFileExit },
     },
     sub_menu_item_t{ "g", "get",
          sub_sub_menu_item_t{ "n", "new", &cliFileGetNew },
          sub_sub_menu_item_t{ "m", "merge", &cliFileGetMerge },
      },
      sub_menu_item_t{ "p", "put",
           sub_sub_menu_item_t{ "c", "current file", &cliFilePutCurrent },
           sub_sub_menu_item_t{ "n", "new file", &cliFilePutNew },
       },
  },
  { "l", "line",
    sub_menu_item_t{ "v", "vertical",
         sub_sub_menu_item_t{ "o", "origin", &cliCreateLineVerticalOrigin },
         sub_sub_menu_item_t{ "e", "endpoint", &cliCreateLineVerticalEndpoint },
     },
     sub_menu_item_t{ "h", "horizontal",
         sub_sub_menu_item_t{ "o", "origin", &cliCreateLineHorizontalOrigin },
         sub_sub_menu_item_t{ "e", "endpoint", &cliCreateLineHorizontalEndpoint },
    },
    sub_menu_item_t{ "e", "endpoints",
         sub_sub_menu_item_t{ "d", "done", &cliCreateLineEndpoints },
    },
    sub_menu_item_t{ "d", "perpendicular",
         sub_sub_menu_item_t{ "d", "distance", &cliCreateLinePerpendicular },
    },
    sub_menu_item_t{ "p", "parallel",
         sub_sub_menu_item_t{ "s", "side distance", &cliCreateLineParallel },
    },
  },
  { "a", "arcs",
    sub_menu_item_t{ "c", "circle",
         sub_sub_menu_item_t{ "d", "center & diameter", &cliCreateCircleCenterDiameter },
         sub_sub_menu_item_t{ "r", "center & radius", &cliCreateCircleCenterRadius },
         sub_sub_menu_item_t{ "t", "two points", &cliCreateCircleTwoPoints },
     },
     sub_menu_item_t{ "a", "arc",
          sub_sub_menu_item_t{ "d", "center & diameter"},
          sub_sub_menu_item_t{ "r", "center & radius" },
          sub_sub_menu_item_t{ "t", "two points" },
      },
  },
  { "x", "xform",
      sub_menu_item_t{ "t", "trim",
        sub_sub_menu_item_t{ "1", "1 entity", &cliXformTrim1 },
        sub_sub_menu_item_t{ "2", "2 entitys", &cliXformTrim2 },
        sub_sub_menu_item_t{ "c", "circle two endpoints", &cliXformTrimCircle },
      },
      sub_menu_item_t{ "m", "mirror",
          sub_sub_menu_item_t{ "l", "across line" },
      },
      sub_menu_item_t{ "r", "rotate",
        sub_sub_menu_item_t{ "o", "origin" },
        sub_sub_menu_item_t{ "p", "point" },
      },
      sub_menu_item_t{ "l", "translate",
        sub_sub_menu_item_t{ "o", "origin" },
        sub_sub_menu_item_t{ "p", "point" },
      },
      sub_menu_item_t{ "o", "offset",
      sub_sub_menu_item_t{ "c", "chain" },
      },
      sub_menu_item_t{ "f", "fillet",
          sub_sub_menu_item_t{ "r", "radius" , &cliXformFilletRadius },
          sub_sub_menu_item_t{ "d", "diameter" },
      },
      sub_menu_item_t{ "c", "chamfer",
          sub_sub_menu_item_t{ "d", "distances" },
          sub_sub_menu_item_t{ "l", "length" },
      },
  },
  { "v", "view",
      sub_menu_item_t{ "p", "plane",
        sub_sub_menu_item_t{ "x", "xy", &cliViewPlaneXY },
        sub_sub_menu_item_t{ "y", "yz", &cliViewPlaneYZ },
        sub_sub_menu_item_t{ "z", "zx", &cliViewPlaneZX },
        sub_sub_menu_item_t{ "o", "ortho", &cliViewPlaneOrtho }
      },
  },
  { "s", "screen",
      sub_menu_item_t{ "s", "selection",
        sub_sub_menu_item_t{ "a", "select all", &cliScreenSelectAll },
        sub_sub_menu_item_t{ "u", "un-select all", &cliScreenUnSelectAll },
        sub_sub_menu_item_t{ "d", "delete selected", &cliScreenDeleteSelected },
      },
      sub_menu_item_t{ "a", "analyze",
        sub_sub_menu_item_t{ "e", "entity", &cliScreenAnalyzeEntity },
      },
      sub_menu_item_t{ "c", "color",
        sub_sub_menu_item_t{ "w", "white", &cliScreenColorWhite },
        sub_sub_menu_item_t{ "b", "black", &cliScreenColorBlack },
        sub_sub_menu_item_t{ "r", "red", &cliScreenColorRed },
        sub_sub_menu_item_t{ "g", "green", &cliScreenColorGreen },
        sub_sub_menu_item_t{ "l", "blue", &cliScreenColorBlue },
        sub_sub_menu_item_t{ "y", "yellow", &cliScreenColorYellow },
        sub_sub_menu_item_t{ "c", "cyan", &cliScreenColorCyan },
        sub_sub_menu_item_t{ "m", "magenta", &cliScreenColorMagenta },
        sub_sub_menu_item_t{ "e", "grey", &cliScreenColorGrey },
      },
  },
};

void cliPush(std::string c)
{
  if (TextInput)
  {
    text.append(c);
    uiEdit(1, uiEntity{UI_TEXT, UI_MENU_COLOR, text, UI_INPUT_POSITION});
  }
  else
  {
    if (Level == 2)
    {
      for (int x=0; x < 10; x++)
      {
        if (menu[Level1Selection].submenu[Level2Selection].submenu[x].c == c)
        {
          if (menu[Level1Selection].submenu[Level2Selection].submenu[x].cmd == NULL) break;
          (*menu[Level1Selection].submenu[Level2Selection].submenu[x].cmd)();
        }
      }
    }
    if (Level == 1)
    {
      for (int x=0; x < 10; x++)
      {
        if (menu[Level1Selection].submenu[x].c == c)
        {
          Level = 2;
          Level2Selection = x;
        }
      }
    }
    if (Level == 0)
    {
      for (int x=0; x < CLI_MENU_ITEMS; x++)
      {
        if (menu[x].c == c)
        {
          Level = 1;
          Level1Selection = x;
        }
      }
    }
    cliMenu();
  }
}
void cliBackup()
{
  if (TextInput)
  {
    if (text.size() > 2)
    {
      text.pop_back();
    }
    else
    {
      TextInput = false;
      text = "";
      cliMenu();
    }
    uiEdit(1, uiEntity{UI_TEXT, UI_MENU_COLOR, text, UI_INPUT_POSITION});
  }
  else
  {
    if (Level > 0) Level--;
    cliMenu();
  }

}
void cliReturn()
{
  if (TextInput == true)
  {
    TextInput = false;
    TextReady = true;
    uiEdit(1, uiEntity{UI_TEXT, UI_MENU_COLOR, "", UI_INPUT_POSITION});
    if ((*textCallback)() != NULL) (*textCallback)();
    text = "";
    cliMenu();
  }
}
void cliMenu()
{
  if (TextInput)
  {
    return;
  }
  string text = "";
  if (Level == 0)
  {
    for (int x=0; x < CLI_MENU_ITEMS; x++)
    {
      if (x != 0)
      {
        text.append(CLI_MENU_ITEM_SEPERATOR);
      }
      text.append(menu[x].c);
      text.append(CLI_MENU_ITEM_LINK);
      text.append(menu[x].msg);
    }
  }
  if (Level == 1)
  {
    for (int x=0; x < 10; x++)
    {
      if (menu[Level1Selection].submenu[x].c == "") break;

      if (x != 0)
      {
        text.append(CLI_MENU_ITEM_SEPERATOR);
      }
      text.append(menu[Level1Selection].submenu[x].c);
      text.append(CLI_MENU_ITEM_LINK);
      text.append(menu[Level1Selection].submenu[x].msg);

    }
  }
  if (Level == 2)
  {
    for (int x=0; x < 10; x++)
    {
      if (menu[Level1Selection].submenu[Level2Selection].submenu[x].c == "") break;

      if (x != 0)
      {
        text.append(CLI_MENU_ITEM_SEPERATOR);
      }
      text.append(menu[Level1Selection].submenu[Level2Selection].submenu[x].c);
      text.append(CLI_MENU_ITEM_LINK);
      text.append(menu[Level1Selection].submenu[Level2Selection].submenu[x].msg);

    }
  }
  uiEdit(0, uiEntity{UI_TEXT, UI_MENU_COLOR, text, UI_MENU_POSITION});
  uiEdit(3, uiEntity{UI_TEXT, RED, "", UI_HINT_POSITION});
}
void cliInit()
{
  args_t args = mainGetArgs();
  if (args.args.find("-fullscreen") != std::string::npos)
  {
    glutFullScreen();
  }
  if (args.args.find("-file") != std::string::npos)
  {
    vector<string> array = split(args.args, ' ');
    for (int x = 0; x < array.size(); x++)
    {
      if (array[x] == "-file")
      {
        CurrentFile = array[x+1];
        fileOpen(CurrentFile);
        cout << KGREEN << "-> Opening " << CurrentFile << KNORMAL << endl;
      }
    }
  }
}
