def get_subnetinfo():
    host = []
    subnet_info = {}

    subnet_info["network"] = input("Input Network Address : ")
    subnet_info["subnetmask"] = input("Input Subnet Mask : ")
    subnet_num = int(input("How many subnets : "))
    
    for i in range(subnet_num):
        host_num = int(input("Subnet"+ str(i+1) +" : How many hosts : "))
        host.append(host_num)
    
    subnet_info["host"] = host


    return subnet_info




if __name__ ==  "__main__":

    a = get_subnetinfo()
    
