![alt text](https://github.com/rileyhora/Keymap/blob/c346b8844dbca9c3a19cb8b16fb92c7207286d0e/Images/IMG-2922.jpg)

### Why Change Layouts?
During my psychology undergraduate studies I experienced pain in my hands and wrists.

I started to research which types of keyboards might help my wrist and hand pain. I found some people had to stop work for weeks to heal or needed surgery. It seemed like spending time learning a more ergonomic set up might help prevent a similar outcome for me. I found ortholinear, split and columnar keyboards to be my main options. Within these catagories there are more considerations, how many thumb keys, no 6th column for modifiers. My main focus was reducing finger movement.

I became worried it would be difficult to learn new muscle memory so I modified the software on my current keyboard to try out Colemak-dh. This is a character layout designed to reduce finger movement. After about 5 hours I was up to 30 words per minute, fast enough for daily use knowing I would become even faster over time. I started to read that some people loved coding with keyboard layers because it made typing symbols so much more accurate, which sounded great.

![alt text](https://github.com/rileyhora/Keymap/blob/c346b8844dbca9c3a19cb8b16fb92c7207286d0e/Images/IMG-2923.png)

### Open Source Project Plans
My research brought me to an [open source keyboard](https://github.com/jimmerricks/swoop "Swoop") with the key layout I thought would be most comfortable. The split columnar design fit my needs because it has 5x3 keys for 8 fingers and a 3 key cluster for each thumb. Keys are aligned in perfect columns to reduce diagonal movement and are staggered in rows to fit the length of each individual finger. This removes the modifier keys to further reduce pinky stretch but still allows me to have an individual key assigned to each character of the alphabet.

In theory this sounded great for my health, but was I loosing functionality not having modifiers, esc, arrows, enter, etc.? One ergonomic keyboard user online recommended using QMK, an open source keyboard software, which is highly customizable with some effort. They mentioned Auto-Shift and Combos to replace the missing keys, along with changing layers depending on a thumb key press. Auto-Shift works by automatically changing to a shifted character if the key is held. Combinations will allow me to stay on the base layer but have access to actions such as esc with quickly pressing two keys at the same time.

I decided to give this a try, so it was time to pick which materials to order. I picked the same switches as the last traditional layout keyboard I built because I know the 63.5g bottom out actuation force works well for me. I can rest my fingers but they are not difficult to press. I also like the ultra-high-molecular-weight polyethylene stems without a tactile bump for a smooth key press. I chose acrylic for bottom plate, as it would allow me to see my completed soldering work on the underside of the board, and carbon fiber for the top plate to add some texture and strength.

### Learning How to Solder
I practiced soldering on some old broken components, but this was not enough preparation for the difficulty of this project. I started with some of the larger components such as the reset switch and trrs connector, which worked well. I then moved on to the diodes which took over thirty minutes to solder one because they are so small. With practice I became much more efficient and soldered 220 components which took about 8 hours.

![alt text](https://github.com/rileyhora/Keymap/blob/c346b8844dbca9c3a19cb8b16fb92c7207286d0e/Images/IMG-2698.jpg)
![alt text](https://github.com/rileyhora/Keymap/blob/c346b8844dbca9c3a19cb8b16fb92c7207286d0e/Images/IMG-2704.jpg)
![alt text](https://github.com/rileyhora/Keymap/blob/c346b8844dbca9c3a19cb8b16fb92c7207286d0e/Images/Micro.jpg)
![alt text](https://github.com/rileyhora/Keymap/blob/c346b8844dbca9c3a19cb8b16fb92c7207286d0e/Images/IMG-2908.jpg)

### Iterative Changes to the Key-Map in C
At first I looked at the key-maps available for 36-key layouts, but they seemed to lack most of the functionality I researched. Over winter break I spent a few days reading QMK documentation to understand the possibilities and started to implement them in C. Key combinations, such as two characters on the top row as esc, were easy to memorize because I made the combinations and layers that made sense to me. At first I was receiving errors in my C code, but it was fun to debug and prevent similar mistakes. When I wanted more functionality, I'd add another layer or combination and try it out. 

This process was extremely satisfying as I enjoyed the flexibility of working in C. I found in QMK documentation that a key can be held down while changing layers. This allowed me to use ctrl from one layer plus a character from another layer, so I have not lost any shortcuts. Auto-Shift was giving me shifted symbols when that was not my desired input. I was able to remove the Auto-Shift functionality from all the keys to remove duplicate inputs. Over time I found 175 milliseconds is a good wait time for me to avoid accidental shifts. Over the course of a month the layout became exactly what I wanted. I was continually surprised that the layers and combinations were so much easier to type than my previous finger-stretching across the board. My error rate for symbols dramatically dropped increasing my coding focus and speed.

After a month I've had increased comfort and accuracy with no wrist or hand pain. I am very satisfied that I've invested the time to design and learn an alternative layout for typing. The alignment of keys and using my left thumb for backspace, layer change, and delete seem an obvious choice compared to a traditional layout. Each time I work with this keyboard I'm reminded how exciting it can be to work with technology and iteratively improve a project.

![alt text](https://github.com/rileyhora/Keymap/blob/c346b8844dbca9c3a19cb8b16fb92c7207286d0e/Images/IMG-2914.jpg)
