int		ft_atoi(const char *str);											преобразует строку в число до встречи первого не цифрового символа, пропускает пробелы в начале
void	ft_bzero(void *s, size_t n);										устанавливает первые n байтов области, начинающейся с s в нули
void	*ft_calloc(size_t n, size_t size);									выделяет память, заполняет ее нулями
int		ft_isalnum(int ch); 												возращает не ноль, если символ число или буква, иначе 0
int		ft_isalpha(int ch); 												возращает не ноль, если символ буква, иначе 0
int		ft_isascii(int ch); 												возращает не ноль, если символ входит в таблицу ASCII
int		ft_isblank(int ch); 												возращает не ноль, если символ ' ' или '\t'
int		ft_iscntrl(int ch); 												возращает не ноль, если управляющий символ
int		ft_isdigit(int ch); 												возращает не ноль, если символ число
int		ft_isgraph(int ch); 												возращает не ноль, если символ печатный (но не пробел)
int		ft_islower(int ch); 												возращает не ноль, если символ буква в нижнем регистре
int		ft_isprint(int ch); 												возращает не ноль, если символ печатный (в т.ч. пробел)
int		ft_isspace(int ch); 												возращает не ноль, если символ ' ', '\f', '\n', \r, '\t', '\v'.
int		ft_isupper(int ch); 												возращает не ноль, если символ буква в вернхнем регистре
int		ft_isxdigit(int ch); 												возращает не ноль, если символ шестнадцатиричной системы исчисления
char	*ft_itoa(int n); 													преобразует число в строку
void	ft_lstadd_back(t_list **alst, t_list *new); 						добавляет элемент в конец списка
void	ft_lstadd_front(t_list **alst, t_list *new);						добавляет элемент в конец списка
void	ft_lstclear(t_list **lst, void (*del)(void *)); 					удаляет весь список с помощью переданной функции и освобождает память
void	ft_lstdelone(t_list *lst, void (*del)(void *)); 					удаляет элемент списка с помощью переданной функции и освобождает память
void	ft_lstiter(t_list *lst, void (*f)(void *)); 						применяет переданную функцию ко всем элементам списка
t_list	*ft_lstlast(t_list *lst);											возвращает последний элемент списка
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));	создает новый список, копируя старый и применяя к его элементам функцию
t_list	*ft_lstnew(void *content);											создает новый список
int		ft_lstsize(t_list *lst);											возвращает количество элементов списка
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);			копирует из src в dst n байт или пока не встретит символ n
void	*ft_memchr(const void *arr, int c, size_t n);						ищет символ в массиве и возвращает указатель на этот символ. Если после проверки n байтов символ не найден, возвращает NULL
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n);			сравнивает n байт двух участков памяти,
void	*ft_memcpy(void *dst, const void *src, size_t n);					копирует n байт из src в dst, результат не определен, если src и dst пересекаются лучше использовать memmove
void	ft_memdel(void **ap);												освобождает память и устанавливает указатель на NULL
void	*ft_memmove(void *dst, const void *src, size_t n);					копирует n байт из src в dst через промежуточный буфер, безопасно, если dst и src пересекаются
void	*ft_memset(void *destination, int c, size_t n); 					заполняет n байт массива destination переданным символом
void	ft_putchar(char c); 												печать символа в стандартный поток вывода
void	ft_putchar_fd(char c, int fd);										печать символа в файл дескриптор
void	ft_putendl(char const *s);											печать строки со '\n' в конце в стандартный поток вывода
void	ft_putendl_fd(char *s, int fd); 									печать строки со '\n' в конце в файл дескриптор
void	ft_putnbr(int n);													печать числа в стандартный поток вывода
void	ft_putnbr_fd(int n, int fd);										печать числа в файл дескриптор
void	ft_putstr(char const *s);											печать строки в стандартный поток вывода
void	ft_putstr_fd(char *s, int fd);										печать строки в файл дескриптор
char	**ft_split(char const *s, char c);									разбивает строку на слова и записывает их в массив строк
int		ft_strcasecmp(const char *str1, const char *str2);					сравнение двух строк без учета регистра
char	*ft_strcasestr(const char *str1, const char *str2); 				аналог strstr без учета регистра
char	*ft_strcat(char *dst, const char *src); 							добавляет строку src в конец строки dst, не выделяет память
char	*ft_strchr(const char *str, int ch);								ищет символ в строке (в т.ч. '\0') и возвращает указатель на этот символ. Если после проверки n байтов символ не найден, возвращает NULL
void	ft_strclr(char *s); 												устанавливает значения строки в '\0'
int		ft_strcmp(const char *str1, const char *str2);						сравнивает строки, возвращает 0, если они идентичны
char	*ft_strcpy(char *dst, const char *src); 							копирует строку src в строку dst
void	ft_strdel(char **as);												освобождает память и устанавливает указатель на NULL
char	*ft_strdup(const char *str);										выделяет память, создает копию строки и возращает ее
int		ft_strequ(char const *s1, char const *s2);							сравнивает две строки, возвращает 1, если идентичны. Работает, если передать NULL
void	ft_striter(char *s, void (*f)(char *));								применяет переданную функцию ко всем элементам строки
void	ft_striteri(char *s, void (*f)(unsigned int, char *));				применяет переданную функцию ко всем элементам строки, индекс элемента строки - первый аргумент переданной ф-ии
char	*ft_strjoin(char const *s1, char const *s2);						выделяет память и объединяет строки
size_t	ft_strlcat(char *dst, const char *src, size_t n);					объединяет строки, в конец всегда ставит '\0', общая длина строки не больше n, возвращает длину получившейся строки
size_t	ft_strlcpy(char *dst, const char *src, size_t n);					копирует из строки src в буфер dst не более чем size - 1 символов, в конец всегда ставит '\0', возвращает длину строки src
size_t	ft_strlen(const char *str);											возвращает длину строки
char	*ft_strlowcase(char *str);											преобразует все буквы в строчные
char	*ft_strmap(char const *s, char (*f)(char));							копирует строку, выделяя память и применяя функцию ко всем символам ихсодной строки
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));			копирует строку, выделяя память и применяя функцию ко всем символам ихсодной строки, индекс элемента строки - первый аргумент переданной ф-ии
int		ft_strncasecmp(const char *str1, const char *str2, size_t n);		сравнивает n элементов двух строк без учета регистра
char	*ft_strncat(char *dst, const char *src, size_t n);					присоединяет n элементов src к dst, устанавливает в конец '\0', не безопасная
int		ft_strncmp(const char *str1, const char *str2, size_t n);			сравнивает n элементов двух строк
char	*ft_strncpy(char *dst, const char *src, size_t n);					копирует n элементов строки src в dst, заполняет нулями, если src > dst
int		ft_strnequ(char const *s1, char const *s2, size_t n);				сравнивает n элементов двух строк, возвращает 1, если идентичны. Работает, если передать NULL
char	*ft_strnew(size_t size);											создает строку размером size + 1, заполняет ее '\0'
char	*ft_strnstr(const char *str1, const char *str2, size_t n);			ищет в первых n байтах первое вхождение строки (за исключением '\0') str1 в строку str2. Если строка str1 имеет нулевую длину, то функция вернет указатель на начало строки str2
char	*ft_strrchr(const char *str, int ch);								ищет последнее вхождение символа (в т.ч'\0') ch в строку str.
char	*ft_strstr(const char *str1, const char *str2);						ищет первое вхождение строки (за исключением '\0') str1 в строку str2. Если строка str1 имеет нулевую длину, то функция вернет указатель на начало строки str2
char	*ft_strtrim(char const *s1, char const *set);						удаляет в начале и в конце строки s1 символы, переданные в строке set.
char	*ft_strupcase(char *str);											преобразует все буквы в заглавные
char	*ft_substr(char const *s, unsigned int start, size_t len);			выделяет память и создает копию подстроки s, длиной s, начинающейся с индекса start
int		ft_tolower(int ch);													переводит букву в нижний регистр
int		ft_toupper(int ch);													переводит букву в верхний регистр
