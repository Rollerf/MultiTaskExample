#include <Arduino.h>

int counter = 0;
int counter2 = 0;

void task1(void *parameter)
{
  for (;;)
  {
    Serial.print("Task 1 - counter: ");
    Serial.println(counter);
    counter++;
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void task2(void *parameter)
{
  for (;;)
  {
    Serial.print("Task 2 - counter: ");
    Serial.println(counter2);
    counter2++;
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}
void setup()
{
  Serial.begin(115200);

  xTaskCreate(
      task1,    // Function that should be called
      "Task 1", // Name of the task (for debugging)
      1000,     // Stack size (bytes)
      NULL,     // Parameter to pass
      1,        // Task priority
      NULL      // Task handle
  );

  xTaskCreate(
      task2,    // Function that should be called
      "Task 2", // Name of the task (for debugging)
      1000,     // Stack size (bytes)
      NULL,     // Parameter to pass
      1,        // Task priority
      NULL      // Task handle
  );
}

void loop()
{
  // Empty. Things are done in Tasks.
}