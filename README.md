# myDB
This is a CLI based database in C with is capable of CRUD operations. 
---
## Links
#### Download Binary (linux): https://github.com/VedantParte23/myDB/releases/download/v1/my
---

## How to run

Binary downloaded (linux):
```bash
chmod +x my
./my
```
Compile from the project
```bash
  gcc main.c db.c -o my
  ./my
```
---

## Commands available

| Command | arguments     | Description              |
|:--------:|:----------------:|:--------------------------:|
| create | db_name.db     | Create a new database    |
| write  | db_name.db     | Insert records           |
| read   | db_name.db     | Display records          |
| update | db_name.db     | Update by ID             |
| delete | db_name.db     | Delete database          |
| man    | —              | Show commands            |
| lf     | —              | List files               |
| dbcls  | —              | Clear screen             |
| exit   | —              | Exit program             |

---

## Data Structure
```c
typedef struct
{
    int id;
    char name[50];
    char data[200];
} Info;

```
---
## Project Structure
```myDB-tree
myDB
├──  main.c                 
├──  db.c               
├──  db.h              
├──  README.md               
```
---

### Licence
MIT: Do what you feeeeel. 

