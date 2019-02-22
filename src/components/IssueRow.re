[%bs.raw {|require('./IssueRow.css')|}];

let component = ReasonReact.statelessComponent("IssueRow");

let make = (~id, ~title, _children) => {
  ...component,
  render: _self =>
    <tr>
      <td className="borderedStyle"> {ReasonReact.string(id)} </td>
      <td className="borderedStyle"> {ReasonReact.string(title)} </td>
    </tr>,
};