import random

#Задача 1
numbers = [random.randint(-1000, 1000) for _ in range(1000)] # Создаём список из 1000 случайных чисел
print("Исходные числа (первые 10):", numbers[:10])
numbers.sort()
print("Отсортированные (первые 10):", numbers[:10])
print()

#Задача 2
arr = [random.randint(50, 100) for _ in range(20)] # массив из случайных чисел от 50 до 100
print("Массив [50,100] до сортировки:", arr)
arr.sort()
print("После сортировки:", arr)
print()

#Задача 3
matrix = [[random.randint(5, 61) for _ in range(4)] for _ in range(6)] # двумерный массив
print("Двумерный массив до сортировки:")
for row in matrix:
    print(row)

matrix.sort(key=lambda x: x[0]) # Сортируем по первому столбцу
print("После сортировки по первому столбцу:")
for row in matrix:
    print(row)
print()

#Задача 4
students = ["Иванов", "Митяев", "Котов", "Чистяков", "Акользин", "Дешко", "Журавлев"]
print("До сортировки:", students)
students.sort(key=str.lower)
print("После сортировки:", students)
