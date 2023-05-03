# {network, subnetmask, host[]}로 구성된 subnet_info 반환
def get_subnetinfo():
    host = []
    subnet_info = {} #{network, subnetmask, host[]}

    subnet_info["network"] = input("Input Network Address : ") #network 입력 string
    subnet_info["subnetmask"] = input("Input Subnet Mask : ") #subnetmask 입력 int
    subnet_num = int(input("How many subnets : "))#int 타입의 subnet 개수
    
    for i in range(subnet_num):
        host_num = int(input("Subnet"+ str(i+1) +" : How many hosts : "))
        host.append(host_num)
    
    host = sorted(host, reverse=True)
    subnet_info["host"] = host #host 정보가 들어가 있는 int 배열


    return subnet_info



def cal_subnet(subnet_info):
    network_split = subnet_info["network"].split(".")

    ID = network_split
    if int(subnet_info["subnetmask"])>=24:
        ID[3] = 0
    elif int(subnet_info["subnetmask"])>=16 & int(subnet_info["subnetmask"])<24:
        ID[3] = 0
        ID[2] = 0


    subnet = 0 #번호 
    print("          ==== Subnet Calculation Result by NamyoungCho ====\n")
    print("Subnet  Network ID       Subnet Mask       Range      Broadcast")
    for host in subnet_info["host"]:
        bi = 1 #host 비교용
        broad = 0
        subnet=subnet+1
        
        for bit in range(32):#최대비트수 32
            if host >= bi: #host가 2진수 bi 보다 크다면 bi*2
                broad = broad + bi
                bi *=2

            elif host < bi: #host가 bi보다 작다면 break 현재 subnetmask를 subnet_mask에 저장
                subnet_mask = 32-bit
                break

#subnet_mask별로 찢음
        if subnet_mask >= 24:
            network = network_split[0]+"." + network_split[1] + "." + str(ID[2]) + "."
            network_ID = network + str(ID[3]) 
            broadcast = network + str(ID[3] + broad)
            rng = network+str(ID[3]+1)+"-"+network+str(ID[3] + broad-1)+"("+str(broad-1) + "EA)"

            print(str(subnet) +"  "+ network_ID+"  " + str(subnet_mask)+"     " + rng+"      " + broadcast)
            ID[3] = ID[3]+bi

        
        elif subnet_mask>=16 & subnet_mask<24:
            network = network_split[0]+"."+network_split[1]+"."
            network_ID = network + str(ID[2]) + "." + str(ID[3])
            third = int(ID[2]+(broad-255)/256)
            broadcast = network + str(third) + ".255" #broad 255 빼고 256으로 나눔
            rng = network + str(ID[2])+"."+ str(ID[3]+1) + "-" + network + str(third)+ ".254" +"(" + str(broad-1) + "EA)"

            print(str(subnet) + "  " + network_ID+"  " + str(subnet_mask)+"     " + rng+"      " + broadcast)
            ID[2] = int(ID[2] + (bi/256))



if __name__ ==  "__main__":
    subnet_info = get_subnetinfo()
    cal_subnet(subnet_info)
