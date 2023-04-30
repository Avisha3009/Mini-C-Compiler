with open("icgnew.txt", 'r') as f:
    f1 = open("tg.txt", 'w')
    data = f.read().splitlines()

    arrjmp = ['==', '!=', '<', '<=', '>', '>=']
    mapjmpstmt = {'==':'JE', '!=':'JNE', '<':'JL', '<=':'JLE', '>':'JG', '>=':'JGE'}

    for line in data:
        if "=" in line and "if" not in line:
            a,b = line.split('=')[0].strip(), line.split('=')[1].strip()
            x, y = None, None
            arr = ['+', '-', '*', '/', '&', '|', '^','**','<<','>>']
            ma = {'+':'ADD', '-':'SUB', '*':'MUL', '/':'DIV', '&':'AND', '|':'OR', '^':'XOR','**':'POW','<<':'SHL','>>':'SHR'}
            if '+' in b or '-' in b or '*' in b or '/' in b or '&' in b or '|' in b or '^' in b:
                for cc in arr:
                    if cc in b:
                        x, y = b.split(cc)
                        if x[0] == 't' and y[0] == 't':
                            if len(x) >= 2 and x[1] in '1234567890' and len(y) >= 2 and y[1] in '1234567890':
                                f1.write(ma[cc] + ' r' + x[1:] + ' '+ y + ' ' + a + '\n')
                                print(ma[cc] + ' r' + x[1:] + ' r' + y[1:] + ' ' + a + '\n')
                                break
                        if x[0] == 't':
                            if len(x) >= 2 and x[1] in '1234567890':
                                f1.write(ma[cc] + ' r' + x[1:] + ' ' + y + ' ' + a + '\n')
                                print(ma[cc] + ' r' + x[1:] + ' ' + y + ' ' + a + '\n')
                                break
                        if y[0] == 't':
                            if len(y) >= 2 and y[1] in '1234567890':
                                f1.write(ma[cc] + ' r' + y[1:] + ' ' + x + ' ' + a + '\n')
                                print(ma[cc] + ' r' + y[1:] + ' ' + x + ' ' + a + '\n')
                                break
                        # f1.write('')
                        f1.write('MOV ' + x + ' r12\n')
                        print('MOV ' + x + ' r12\n')
                        f1.write(ma[cc] + ' r12 ' + y + ' ' + a + '\n')
                        print(ma[cc] + ' r12 ' + y + ' ' + a + '\n')
            else:
                if a[0] == 't' and b[0] == 't':
                    if len(a) >= 2 and a[1] in '1234567890' and len(b) >= 2 and b[1] in '1234567890':
                        f1.write('MOV' + ' r' + b[1:] + ' ' + a + '\n')
                        print('MOV' + ' r' + b[1:] + ' ' + a + '\n')
                        

                        continue
                if a[0] == 't':
                    if len(a) >= 2 and a[1] in '1234567890':
                        f1.write('MOV ' + b + ' r' + a[1:] + '\n')
                        print('MOV ' + b + ' r' + a[1:] + '\n')
                        f1.write('MOV ' +' r' + a[1:] + ' ' + a + '\n')
                        #print('MOV ' + b + ' r' + a[1:] + '\n')
                        continue
                if b[0] == 't':
                    if len(b) >= 2 and b[1] in '1234567890':
                        f1.write('MOV ' + b + ' r' + b[1:] + '\n')
                        print('MOV ' + b + ' r' + b[1:] + '\n')
                        f1.write('MOV' + ' r' + b[1:] + ' ' + a + '\n')
                        print('MOV' + ' r' + b[1:] + ' ' + a + '\n')
                        continue
                # f1.write('')
                f1.write('MOV ' + b + ' r12\n')
                print('MOV ' + b + ' r12\n')
                f1.write('MOV' + ' r12 ' + a  + '\n')
                print('MOV' + ' r12 ' + a  + '\n')

        elif "if" in line:
            ifcode,a,op, b, gotocode, label = line.split()
            f1.write('MOV ' + a + ' r12\n')
            print('MOV ' + a + ' r12\n')
            f1.write('CMP ' + 'r12 ' + b + '\n')
            print('CMP ' + 'r12 ' + b + '\n')
            f1.write(mapjmpstmt[op] + ' ' + label + '\n')
        
        elif "goto" == line[:4]:
            gotocode, label = line.split()
            f1.write('JMP ' + label + '\n')
            print('JMP ' + label + '\n')
        
        elif "return" == line[:6]:
            f1.write("RET\n")
            print("RET\n")

        else:
            f1.write(line + '\n')
            print(line + '\n')
        # f1.close()
