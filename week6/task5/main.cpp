#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

using TasksInfo = std::map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const std::string& person) const {
    return person_tasks.at(person);
  }
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const std::string& person) {
    TasksInfo& person_info = person_tasks[person];
    ++person_info[TaskStatus::NEW];
  }
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string& person, int task_count) {
    if (person_tasks.count(person) == 0) {
        return {};
    }

    TasksInfo& person_stat = person_tasks[person];
    TasksInfo touched, untouched;
    for (size_t i = 0; i + 1 < statuses.size() && task_count > 0; ++i){
        int status_count = person_stat[statuses[i]];
        int perfomed = std::min(task_count, status_count);
        touched[statuses[i+1]] = perfomed;
        if (status_count - perfomed > 0) {
            untouched[statuses[i]] = status_count - perfomed;
        }

        task_count -= perfomed;
    }

    for(size_t i = 0; i < statuses.size(); i++) {
        int comeIn = touched[statuses[i]]; // Столько пришло
        int comeOut = (statuses[i] == TaskStatus::DONE) ? 0 : touched[statuses[i+1]]; // Столько ушло
        person_stat[statuses[i]] += (comeIn-comeOut);
    }

    return {touched, untouched};
  }
private:
    std::map<std::string, TasksInfo> person_tasks;
    const std::vector<TaskStatus> statuses = {TaskStatus::NEW, TaskStatus::IN_PROGRESS, TaskStatus::TESTING, TaskStatus::DONE};
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  std::cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << std::endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  std::cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  std::cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  std::cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  std::cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  std::cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  std::cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}

/*
Failed case #1/102: (Wrong answer)
Неправильный результат в 1 строке

Input:
AddNewTasks Alice 5
PerformPersonTasks Alice 5
PerformPersonTasks Alice 5
PerformPersonTasks Alice 1
AddNewTasks Alice 5
PerformPersonTasks Alice 2
GetPersonTasksInfo Alice
PerformPersonTasks Alice 4
GetPersonTasksInfo Alice

Your output:
[]
[{"NEW": 0, "IN_PROGRESS": 5, "TESTING": 0, "DONE": 0}, {}]
[{"NEW": 0, "IN_PROGRESS": 0, "TESTING": 5, "DONE": 0}, {}]
[{"NEW": 0, "IN_PROGRESS": 0, "TESTING": 0, "DONE": 1}, {"TESTING": 4}]
[]
[{"NEW": 0, "IN_PROGRESS": 2, "TESTING": 0, "DONE": 0}, {"NEW": 3}]
{"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
[{"NEW": 0, "IN_PROGRESS": 3, "TESTING": 1, "DONE": 0}, {"IN_PROGRESS": 1}]
{"NEW": 0, "IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}

Correct output:
[]
[{"IN_PROGRESS": 5}, {}]
[{"TESTING": 5}, {}]
[{"DONE": 1}, {"TESTING": 4}]
[]
[{"IN_PROGRESS": 2}, {"NEW": 3, "TESTING": 4}]
{"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
[{"IN_PROGRESS": 3, "TESTING": 1}, {"IN_PROGRESS": 1, "TESTING": 4}]
{"IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}
 (Time used: 0.00/1.00, preprocess time used: 0/None, memory used: 48103424/536870912.)
*/