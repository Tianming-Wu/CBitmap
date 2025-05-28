# CBitmap
lightweight bitmap editor for single color oled displats (128x64 ssd1306)

Feel free to submit bug report.

# Features
- Builtin bitmap editor, supports painting by mouse. Touchscreen is not specially supported nor tested.
- View region supports transform like scaling and moving, with reset button.
- Import from png, jpg/jpeg and svg images, and supports identification through transparency.
- Import/Export from/to cpp code object.
- Paint brush like pixel, line, rectangle and circle, and supports filling.
- Undo / Redo support.
- Configurable visual effects (colors, grid).

# UI
![Main window](https://github.com/user-attachments/assets/70c47eeb-fd64-4875-897f-219b236fbc82)
![Settings](https://github.com/user-attachments/assets/ef3ecf0e-87a5-4072-b3c3-074f7cbf9cb3)
![Import from image](https://github.com/user-attachments/assets/f84c1b35-fcf8-4c2b-a1b0-dd77f381faa8)
![Import from code](https://github.com/user-attachments/assets/05983db6-2889-4cc4-9638-688a1ef7ff40)

# Note
- Selection is currently not available, and may be added in the future releases.
- Only Import/Export code as Padded (Horizontal) is supported currently. This is right for Adafruid_ssd1306, but for some libraries (lexus2k/ssd1306) you need to manually rotate it by -90 degrees.
- On color / Off color are not currently editable.
- Adjust is not available. Visual effects are completed, but has no actual function.
- Configurations are not saved, and will be lost after closing the main window.

# About
The project is based on Qt 6.4.2.

Spacial Thanks to [Icons8](https://icons8.com) for providing free icons for the project.
