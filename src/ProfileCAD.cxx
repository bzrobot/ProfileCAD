#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkSphereSource.h>
#include <vtkCallbackCommand.h>
#include <vtkCommand.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>

using namespace std;

pthread_t vtk_thread;

void KeypressCallbackFunction (
  vtkObject* caller,
  long unsigned int eventId,
  void* clientData,
  void* callData );

int cli_main()
{
  int status;
  string cmd;
  while(1)
  {
    cout << "> ";
    cin >> cmd;
    if (cmd == "exit")
    {
      //kill(pid, SIGKILL);
      exit(0);
    }
    if (cmd == "test")
    {
      cout << "Its working!\n";
    }
  }
}
void *vtk_main(void *)
{
  // Create a sphere
  vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
  sphereSource->SetCenter(0.0, 0.0, 0.0);
  sphereSource->SetRadius(5.0);
  sphereSource->Update();

  vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(sphereSource->GetOutputPort());

  // Create an actor
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);

  // A renderer and render window
  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->SetSize(500,400); //(width, height)
  renderWindow->AddRenderer(renderer);

  // An interactor
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);

  vtkSmartPointer<vtkCallbackCommand> keypressCallback = vtkSmartPointer<vtkCallbackCommand>::New();
  keypressCallback->SetCallback ( KeypressCallbackFunction );
  renderWindowInteractor->AddObserver ( vtkCommand::KeyPressEvent, keypressCallback );

  renderer->AddActor(actor);
  renderer->SetBackground(0,0,0); // Background color black
  renderWindow->Render();
  renderWindowInteractor->Start();
  return NULL;
}
int main()
{
  if(pthread_create(&vtk_thread, NULL, vtk_main, NULL))
  {
    fprintf(stderr, "Error creating thread!\n");
    return 1;
  }
  cli_main();
}
void KeypressCallbackFunction ( vtkObject* caller, long unsigned int vtkNotUsed(eventId), void* vtkNotUsed(clientData), void* vtkNotUsed(callData) )
{
  vtkRenderWindowInteractor *iren = static_cast<vtkRenderWindowInteractor*>(caller);
  string key = string(iren->GetKeySym());
  printf("Keyress -> %s\n", key.c_str());
  if (key == "Return")
  {
    printf("\tReturn Key!\n");
  }
  if (key == "Escape")
  {
    printf("Bye!\n");
    exit(EXIT_SUCCESS);
  }

}
