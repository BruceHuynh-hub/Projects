library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity sequence_detector is port(
	myInput: in std_logic;
	clk: in std_logic;
	rst: in std_logic;
	myOut: out std_logic);
end sequence_detector;

architecture Controller of sequence_detector is
	type states is (gotNone, got1, got11, got110, got1101, got11010, got110101);
	signal present_state : states; 
	signal next_state : states; 
	
begin 
-- combinational part
	combinational: process(myInput, present_state) begin
		case present_state is
			when gotNone =>
				if (myInput = '0') then
					next_state <= gotNone;
					myOut <= '0';
				else
					next_state <= got1;
					myOut <= '0';
				end if;

			when got1 =>
				if (myInput = '0') then
					next_state <= gotNone;
					myOut <= '0';
				else
					next_state <= got11;
					myOut <= '0';
				end if;
			when got11 =>
				if (myInput = '0') then
					next_state <= got110;
					myOut <= '0';
				else
					next_state <= got11;
					myOut <= '0';
				end if;
			when got110 =>
				if (myInput = '0') then
					next_state <= gotNone;
					myOut <= '0';
				else
					next_state <= got1101;
					myOut <= '0';
				end if;
			when got1101 =>
				if (myInput = '0') then
					next_state <= got11010;
					myOut <= '0';
				else
					next_state <= got11;
					myOut <= '0';
				end if;
			when got11010 =>
				if (myInput = '0') then
					next_state <= gotNone;
					myOut <= '0';
				else
					next_state <= got110101;
					myOut <= '0';
				end if;
			when got110101 =>
				if (myInput = '0') then
					next_state <= gotNone;
					myOut <= '1';
				else
					next_state <= got11;
					myOut <= '1';
				end if;
		end case;
	end process combinational;


-- sequential part
	state_switch: process (clk, rst) begin
		if (rst = '1') then
			present_state <= gotNone;
		elsif (clk'event and clk = '1') then
			present_state <= next_state;
		end if;
	end process state_switch;

end Controller;

