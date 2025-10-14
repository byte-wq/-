import random #генератор случайных чисел

# 1. Сортировка выбором по возрастанию
def selection_sort_ascending(a): #сортировка выбором по возрастанию
    for i in range(len(a) - 1): # перебираем все элнменты массива кроме последнего
        min_i= i # минимальный элемент
        for j in range(i + 1, len(a)): # ищем реальный минимальный элемент в подмассиве a
            if a[j] < a[min_i]: #Если нашли элемент меньше текущего, обновляем  минимум
                min_i = j
        a[i], a[min_i] = a[min_i], a[i]

random.seed(1) # будет генерироваться одна и та же последовательность "случайных" чисел.
n1 = 26 # размер массива
array1 = [random.randint(2, 103) for _ in range(n1)]
print("Пункт 1 — исходный массив:", array1)
selection_sort_ascending(array1)  # сортируем по возрастанию
print("Пункт 1 — отсортировано по возрастанию:", array1)
print()

#2. Сортировка выбором по убыванию
def selection_sort_descending(ap):
    for i in range(len(ap) - 1):
        max_i = i
        for j in range(i + 1, len(ap)):
            if ap[j] > ap[max_i]:
                max_i = j
        ap[i], ap[max_i] = ap[max_i], ap[i]

random.seed(2)
n2 = 18
array2 = [random.randint(0, 100) for _ in range(n2)]
print("Пункт 2 — исходный массив:", array2)
selection_sort_descending(array2)
print("Пункт 2 — отсортировано по убыванию:", array2)
print()

# --- 3. Сортировка телефонных номеров по возрастанию ---
def normal_phone(phone_str):
    digits = ''.join(ch for ch in phone_str if ch.isdigit())
    return int(digits) if digits else 0

def selection_sort_phones_by_numeric_value(phone_list):
    for i in range(len(phone_list) - 1):
        min_in = i
        for j in range(i + 1, len(phone_list)):
            if normal_phone(phone_list[j]) < normal_phone(phone_list[min_in]):
                min_in = j
        phone_list[i], phone_list[min_in] = phone_list[min_in], phone_list[i]

phones = [
    "84-45-69",
    "8-800-555-35-35",
    "123-456",
    "09-06-06",
    "+7(919)883-84-24",
    "234567",
    "001-002-003"
]
print("Пункт 3 — исходный список телефонов:", phones)
selection_sort_phones_by_numeric_value(phones)
print("Пункт 3 — отсортировано по возрастанию:", phones)
