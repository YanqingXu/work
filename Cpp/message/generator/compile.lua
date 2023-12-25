
--[[
--
--	load and compile an template file into a callable object, which is used to generate code base on this
--	template tags:
--	<% ... %>  : embbeded code block
--	<%= ... %> : embbeded value
--
--]]
function compile(tfilename, ifilename, ofilename)
	if not tfilename or not ofilename then
		print("#####compile failed, missing parameter!!!")
	end

	local tfile = io.open(tfilename, "r")
	if not tfile then
		return
	end

	local tcontent = tfile:read("*all")
	tfile:close()

	if not tcontent then
		return
	end

	--tcontent = tcontent:gsub("(%s+)(<#[^=]-#>)", function (a, b) if b:sub(-1)=="=" then return a..b else return b end end )
	--tcontent = tcontent:gsub("([ %t]+<#=?)", function (a) if a:sub(-1)=="=" then return a else return "<#" end end )
	--tcontent = tcontent:gsub("(#>%s+\n)", function (a) if a:sub(-1)=="\n" then return "#>" else return a end end )
	--tcontent = tcontent:gsub("(#>[\t ]*\n)", function (a) return "#>"end )
	--tcontent = tcontent:gsub("(\n[\t ]+<#)(=?)", function (a, b) if b=="=" then return a..b else return "\n<#"end end )


	--É¾³ýËùÓÐµÄ'\r'
	tcontent = tcontent:gsub("(\r)", function(a) return "" end)
	
	--É¾³ýÐÐÎ²¿Õ°×
	tcontent = tcontent:gsub("([\t ]+\n)", function (a) return "\n" end)
	
	tcontent = tcontent:gsub("(\n[\t ]*<%%)(=?)", function(a, b) if b == "=" then return a .. b else return "<%" end end)
	tcontent = tcontent:gsub("(\n[\t ]*%%>)", function(a) return "\n%>" end)

	local tcode = "\nlocal ___ret = \"\"\n"
	local pos = 1

	while true do
		local first, last, equal, content = tcontent:find("<%%(=?)(.-)%%>", pos)

		--print("------first,pos-------")
		--print(first,pos)
		--print("------equal,content-------")
		--print(equal,content)

		if not first then
			--match failed
			local s = tcontent:sub(pos)
			if s:sub(1, 1) == "\n" then
			    s = "\n" .. s
			end

			--tcode = tcode .. "ofile:write(\[\[" .. s .. "\]\])\n"
			tcode = tcode .. "___ret = ___ret .. \[\[" .. s .. "\]\]\n"
			break
		end
		
		if first ~= pos then
			local s = tcontent:sub(pos, first - 1)
			if s:sub(1, 1) == "\n" then
			    s = "\n" .. s
			end

			--tcode = tcode .. "ofile:write(\[\[" .. s .. "\]\])\n"
			tcode = tcode .. "___ret = ___ret .. \[\[" .. s .. "\]\]\n"
		end

		if equal == "=" then
			--tcode = tcode .. "ofile:write(" .. content .. ")\n"
			tcode = tcode .. "___ret = ___ret .. " .. content .. "\n"
		else
			tcode = tcode .. content .. "\n"
		end

		pos = last + 1
	end

	-- É¾³ýÐÐÎ²¿Õ°×
	tcode = tcode:gsub("([\t ]+\n)", function (a) return "\n" end)

	tcode = tcode .. "\nreturn ___ret\n"

	local tchunk = assert(loadstring(tcode))
	if not tchunk then
		print ("#####compile failed, invalid template :  ", tfilename)
		--debugTemplate(tfilename)
		return
	end

	local ichunk = nil
	if ifilename and (ifilename ~= "") then
		ichunk = loadfile(ifilename)
		if not ichunk then
			print ("#####compile failed, invalid data file : " , ifilename)
			return
		end
	end
	
	ofile = io.open(ofilename, "w")
	if not ofile then
		print ("#####compile failed, invlaid output file : ", ofilename)
		return
	end

	print ("compile ... [" , ifilename , "] + [" , tfilename , "] = [" , ofilename, "]")
	
	if ichunk then
		ichunk()
	end

	local ocontent = tchunk(ofilename)
	
	ofile:write(ocontent)

	ofile:close()
end
