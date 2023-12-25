messages =
{
	{
		define = "class", name="MsgHttpRequest", category = "MSG_CATEGORY_HTTP", id = "112", base = "Message",
		 attributes =
		 {
		   {type="int8", name = "type"},
		   {type="string", name = "url"},
		   {type="string",name = "auth"},
		   {type="string", name="doc"},
				
		 }
	},
	{
		define = "class", name="MsgHttpResponse", category = "MSG_CATEGORY_HTTP", id = "113", base = "Message",
		 attributes =
		 {
		   {type="string", name="rsp"},
		 }
	},
	
}

