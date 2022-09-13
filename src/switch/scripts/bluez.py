#!/home/roblab/.pyenv/shims/python

import rospy
import hid
import time

print(hid.enumerate())

# VENDOR_ID = 0x057E
# L_PRODUCT_ID = 0x2006
# R_PRODUCT_ID = 0x2007

# def write_output_report(joycon_device, packet_number, command, subcommand, argument):
#     joycon_device.write(command
#                         + packet_number.to_bytes(1, byteorder='big')
#                         + b'\x00\x01\x40\x40\x00\x01\x40\x40'
#                         + subcommand
#                         + argument)

# if __name__ == '__main__':

#     joycon_device = hid.device()
#     joycon_device.open(VENDOR_ID, L_PRODUCT_ID)

#     # 6軸センサーを有効化
#     write_output_report(joycon_device, 0, b'\x01', b'\x40', b'\x01')
#     # 設定を反映するためには時間間隔が必要
#     time.sleep(0.02)
#     # 60HzでJoy-Conの各データを取得するための設定
#     write_output_report(joycon_device, 1, b'\x01', b'\x03', b'\x30')

#     while True:
#         print(joycon_device.read(49))