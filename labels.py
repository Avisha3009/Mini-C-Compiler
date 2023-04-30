f = open("icg_opt.txt", 'r')
count = 0
linelabelmap = {}
data = f.read().splitlines()
for line in data:
    if("goto" in line):
        lineno = line.split("goto")[1].lstrip()
        if lineno not in linelabelmap:
            linelabelmap[lineno] = "L" + str(count)
            count += 1

for i in linelabelmap:
    print(i, linelabelmap[i])

datanew = []

for line in data:
    if("goto" in line):
        lineno = line.split("goto")[1].lstrip()
        line = line.replace(lineno, linelabelmap[lineno])
    datanew.append(line)
    print(line)

f.close()

f = open("icgnew.txt", 'w')

count = 0
for line in datanew:
    if str(count) in linelabelmap:
        f.write(linelabelmap[str(count)] + ":\n")
    f.write(line + "\n")
    count += 1

f.close()


