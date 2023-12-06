import subprocess
import tkinter as tk

def show():
    if input_file_name.get():
        with open(input_file_name.get(), 'r') as file:
            content = file.read()
            input_file.delete(1.0, tk.END)  # 清空Text widget
            input_file.insert(tk.END, content)  # 插入檔案內容到Text widget

def compress():
    command = ["HW8_B113040052.exe", "huffman", "-c", "-i", input_file_name.get(), "-o", output_file_name.get()]
    try:
        subprocess.run(command, check=True)
    except subprocess.CalledProcessError as e:
        print(f"執行檔返回非零退出碼: {e.returncode}")
    except Exception as e:
        print(f"執行檔執行時出現錯誤: {str(e)}")
    if output_file_name.get():
        with open(output_file_name.get(), 'r') as file:
            content = file.read()
            output_file.delete(1.0, tk.END)  # 清空Text widget
            output_file.insert(tk.END, content)  # 插入檔案內容到Text widget

def decompress():
    command = ["HW8_B113040052.exe", "huffman", "-u", "-i", input_file_name.get(), "-o", output_file_name.get()]
    try:
        subprocess.run(command, check=True)
    except subprocess.CalledProcessError as e:
        print(f"執行檔返回非零退出碼: {e.returncode}")
    except Exception as e:
        print(f"執行檔執行時出現錯誤: {str(e)}")
    if output_file_name.get():
        with open(output_file_name.get(), 'r') as file:
            content = file.read()
            output_file.delete(1.0, tk.END)  # 清空Text widget
            output_file.insert(tk.END, content)  # 插入檔案內容到Text widget

root = tk.Tk()
root.title("Huffman")
root.geometry("700x500")

file_content = tk.Frame(root)
file_content.pack()

input_file = tk.Text(file_content, wrap=tk.WORD, width=45, height=20)
input_file.pack(side = tk.LEFT, padx=10)

output_file = tk.Text(file_content, wrap=tk.WORD, width=45, height=20)
output_file.pack(side = tk.LEFT, padx=10)

Enter_frame = tk.Frame(root)
Enter_frame.pack()

button_frame = tk.Frame(root)
button_frame.pack()

label = tk.Label(Enter_frame, text="輸入檔名:")
label.pack(side = tk.LEFT)
input_file_name = tk.Entry(Enter_frame)
input_file_name.pack(side = tk.LEFT)
label = tk.Label(Enter_frame, text="輸出檔名:")
label.pack(side = tk.LEFT)
output_file_name = tk.Entry(Enter_frame)
output_file_name.pack(side = tk.LEFT)
button = tk.Button(Enter_frame, text="確定", command=show)
button.pack(side = tk.LEFT)

button = tk.Button(button_frame, text="壓縮", command=compress)
button.pack(side = tk.LEFT)
button = tk.Button(button_frame, text="解壓縮", command=decompress)
button.pack(side = tk.LEFT)

root.mainloop()


