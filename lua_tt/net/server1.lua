local socket = require "socket"
local server = assert(socket.bind("0.0.0.0",8383))

while true do
	local control = server:accept()	
	while true do
		command,status = control:receive()
		if status == "closed" then
			break
		end
		print(command)
		control:send("ack\n")

	end
end
